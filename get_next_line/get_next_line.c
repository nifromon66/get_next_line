/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:36:37 by nifromon          #+#    #+#             */
/*   Updated: 2024/11/26 12:16:19 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//START
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*store = NULL;
	t_list			*error;
	char			*queue;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	queue = NULL;
	if (inventory(&store, fd) == -1)
	{
		while (store)
		{
			error = store->next;
			free(store->content);
			free(store);
			store = error;
		}
		store = NULL;
	}
	if (!store)
		return (NULL);
	fetch_queue(store, &queue);
	cutting_in(&store);
	if (!queue || queue[0] == '\0')
		return (free(queue), queue = NULL, NULL);
	return (queue);
}

int	inventory(t_list **store, int fd)
{
	int		bill;
	char	*product;

	bill = 0;
	while (!search_newline(*store))
	{
		product = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!product)
			return (bill);
		bill = read(fd, product, BUFFER_SIZE);
		if (bill <= 0)
		{
			free(product);
			product = NULL;
			return (bill);
		}
		product[bill] = '\0';
		stock_replenishment(store, product);
	}
	return (bill);
}

void	stock_replenishment(t_list **store, char *product)
{
	t_list	*new_product;
	t_list	*last_product;

	last_product = ft_lstlast(*store);
	new_product = (t_list *)malloc(sizeof(t_list));
	if (!new_product)
		return ;
	if (!last_product)
		*store = new_product;
	else
		last_product->next = new_product;
	new_product->content = product;
	new_product->next = NULL;
}

void	fetch_queue(t_list *store, char **queue)
{
	int		queue_len;

	if (!store)
		return ;
	queue_len = lstlen_till_newline(store);
	*queue = (char *)malloc(sizeof(char) * (queue_len + 1));
	if (!*queue)
		return ;
	cpylst_to_str(store, *queue);
	return ;
}

void	cutting_in(t_list **store)
{
	t_list	*last_product;
	t_list	*clean_store;
	int		i;
	int		j;
	char	*product;

	product = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	clean_store = (t_list *)malloc(sizeof(t_list));
	if (!product || !clean_store)
		return ;
	last_product = ft_lstlast(*store);
	i = 0;
	j = 0;
	while (last_product->content[i] && last_product->content[i] != '\n')
		i++;
	while (last_product->content[i] && last_product->content[++i])
		product[j++] = last_product->content[i];
	product[j] = '\0';
	clean_store->content = product;
	clean_store->next = NULL;
	free_store(store, clean_store, product);
}

//END
