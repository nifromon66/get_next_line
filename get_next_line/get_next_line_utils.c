/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:55:45 by nifromon          #+#    #+#             */
/*   Updated: 2024/11/25 16:14:55 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//START
#include "get_next_line.h"

int	search_newline(t_list *store)
{
	int	i;

	if (!store)
		return (0);
	while (store)
	{
		i = 0;
		while (store->content[i] && i < BUFFER_SIZE)
		{
			if (store->content[i] == '\n')
				return (1);
			i++;
		}
		store = store->next;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *store)
{
	if (!store)
		return (NULL);
	while (store->next)
		store = store->next;
	return (store);
}

void	cpylst_to_str(t_list *store, char *queue)
{
	int	i;
	int	j;

	if (!store)
		return ;
	i = 0;
	while (store)
	{
		j = 0;
		while (store->content[j])
		{
			if (store->content[j] == '\n')
			{
				queue[i++] = '\n';
				queue[i] = '\0';
				return ;
			}
			queue[i++] = store->content[j++];
		}
		store = store->next;
	}
	queue[i] = '\0';
}

int	lstlen_till_newline(t_list *store)
{
	int	i;
	int	len;

	if (!store)
		return (0);
	len = 0;
	while (store)
	{
		i = 0;
		while (store->content[i])
		{
			if (store->content[i] == '\n')
				return (len + 1);
			i++;
			len++;
		}
		store = store->next;
	}
	return (len);
}

void	free_store(t_list	**store, t_list *clean_store, char *product)
{
	t_list	*pop_up;

	while (*store)
	{
		pop_up = (*store)->next;
		free((*store)->content);
		free(*store);
		*store = pop_up;
	}
	*store = NULL;
	if (clean_store->content[0])
		*store = clean_store;
	else
	{
		free(product);
		product = NULL;
		free(clean_store);
		clean_store = NULL;
	}
}

//END
