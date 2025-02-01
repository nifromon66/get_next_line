/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:40:00 by nifromon          #+#    #+#             */
/*   Updated: 2025/02/01 16:59:56 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//START
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl
{
	char			*content;
	struct s_gnl	*next;
}					t_gnl;

int		gnl_lst_search_newline(t_gnl *store);
t_gnl	*ft_lstlast(t_gnl *store);
char	*gnl_fetch_queue(t_gnl *store);
void	gnl_lst_to_str(t_gnl *store, char *queue);
int		gnl_lst_linelen(t_gnl *store);
void	gnl_cutting_in(t_gnl **store);
void	gnl_free_store(t_gnl **store, t_gnl *clean_store, char *product);
void	gnl_stock_replenishment(t_gnl **store, char *product, int fd);
int		gnl_inventory(t_gnl **store, int fd);
char	*get_next_line(int fd);

#endif

//END
