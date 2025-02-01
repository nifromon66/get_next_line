/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:36:37 by nifromon          #+#    #+#             */
/*   Updated: 2025/02/01 15:22:46 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//START
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl	*store = NULL;
	t_gnl			*error;
	char			*queue;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	queue = NULL;
	if (gnl_inventory(&store, fd) == -1)
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
	gnl_fetch_queue(store, &queue);
	gnl_cutting_in(&store);
	if (!queue || queue[0] == '\0')
		return (free(queue), queue = NULL, NULL);
	return (queue);
}

int	gnl_inventory(t_gnl **store, int fd)
{
	int		bill;
	char	*product;

	bill = 0;
	while (!gnl_lst_search_newline(*store))
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
		gnl_stock_replenishment(store, product);
	}
	return (bill);
}

void	gnl_stock_replenishment(t_gnl **store, char *product)
{
	t_gnl	*new_product;
	t_gnl	*last_product;

	last_product = ft_lstlast(*store);
	new_product = (t_gnl *)malloc(sizeof(t_gnl));
	if (!new_product)
		return ;
	if (!last_product)
		*store = new_product;
	else
		last_product->next = new_product;
	new_product->content = product;
	new_product->next = NULL;
}

void	gnl_fetch_queue(t_gnl *store, char **queue)
{
	int		queue_len;

	if (!store)
		return ;
	queue_len = gnl_lstlinelen(store);
	*queue = (char *)malloc(sizeof(char) * (queue_len + 1));
	if (!*queue)
		return ;
	gnl_lsttostr(store, *queue);
	return ;
}

void	gnl_cutting_in(t_gnl **store)
{
	t_gnl	*last_product;
	t_gnl	*clean_store;
	int		i;
	int		j;
	char	*product;

	product = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	clean_store = (t_gnl *)malloc(sizeof(t_gnl));
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
	gnl_free_store(store, clean_store, product);
}

//END
