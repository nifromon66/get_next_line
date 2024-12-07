/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:49:06 by nifromon          #+#    #+#             */
/*   Updated: 2024/11/26 12:05:02 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//START
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

int		search_newline(t_list *store);
t_list	*ft_lstlast(t_list *store);
void	fetch_queue(t_list *store, char **queue);
void	cpylst_to_str(t_list *store, char *queue);
int		lstlen_till_newline(t_list *store);
void	cutting_in(t_list **store);
void	free_store(t_list	**store, t_list *clean_store, char *product);
void	stock_replenishment(t_list **store, char *product);
int		inventory(t_list **store, int fd);
char	*get_next_line(int fd);

#endif

//END
