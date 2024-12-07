/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:40:00 by nifromon          #+#    #+#             */
/*   Updated: 2024/11/25 15:38:03 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//START
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

int		search_newline(t_list *store);
t_list	*ft_lstlast(t_list *store);
char	*fetch_queue(t_list *store);
void	cpylst_to_str(t_list *store, char *queue);
int		lstlen_till_newline(t_list *store);
void	cutting_in(t_list **store);
void	free_store(t_list **store, t_list *clean_store, char *product);
void	stock_replenishment(t_list **store, char *product, int fd);
int		inventory(t_list **store, int fd);
char	*get_next_line(int fd);

#endif

//END
