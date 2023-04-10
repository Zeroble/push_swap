/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:51:57 by minylee           #+#    #+#             */
/*   Updated: 2023/04/10 21:44:54 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_list			*ft_lstnew(int num);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
int				ft_atoi(const char *c);
void			ft_lst_readall(t_list *lst);
void			ss(t_list **a, t_list **b);
void			sb(t_list **b);
void			sa(t_list **a);
void			rr(t_list **a, t_list **b);
void			rb(t_list **b);
void			ra(t_list **a);
void			rrr(t_list **a, t_list **b);
void			rrb(t_list **b);
void			rra(t_list **a);
void			pb(t_list **a, t_list **b);
void			pa(t_list **a, t_list **b);

#endif
