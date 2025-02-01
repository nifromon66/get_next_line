/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:55:45 by nifromon          #+#    #+#             */
/*   Updated: 2025/02/01 16:55:18 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//START
#include "get_next_line.h"

int	gnl_lst_search_newline(t_gnl *store)
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

t_gnl	*ft_lstlast(t_gnl *store)
{
	if (!store)
		return (NULL);
	while (store->next)
		store = store->next;
	return (store);
}

void	gnl_lst_to_str(t_gnl *store, char *queue)
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

int	gnl_lst_linelen(t_gnl *store)
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

void	gnl_free_store(t_gnl **store, t_gnl *clean_store, char *product)
{
	t_gnl	*pop_up;

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
