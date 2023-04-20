/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:51:57 by minylee           #+#    #+#             */
/*   Updated: 2023/04/20 10:56:51 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_move
{
	int	a_r;
	int	b_r;
	int	a_rr;
	int	b_rr;
	int	score;
}	t_move;

t_list			*ft_lstnew(int num);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
int				ft_atoi(const char *c, int *sign_flag);
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
int				find_mid_value(t_list *a, int argc);
void			split_push(t_list **a, t_list **b, t_list *start, int argc);
void			set_first_elem_min(t_list **a, int argc);
int				is_ascending(t_list *a);
int				init_values(t_list **a, t_list **b, int argc, char **argv);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
void			find_pivots(t_list *a, int argc, int *pivot1, int *pivot2);
void			greedy_rotate(t_list **a, t_list **b, t_move move);
int				calcurate_score(t_move move);
void			calcurate_a(t_list *a, int target, t_move *move, int size);
void			calcurate_b(t_move *move, int idx, int b_size);
void			lst_freeall(t_list **lst);
int				greedy_sort(t_list **a, t_list **b);
int				ft_strncmp(const char *s1, const char *s2, int n);
int				ft_strlen(const char *s);
void			*ft_malloc(size_t size);

#endif
