/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:48:59 by minylee           #+#    #+#             */
/*   Updated: 2023/03/27 19:48:59 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** pa - push a : Take the first element at the top of b and put it at the top of a.
** pb - push b : Take the first element at the top of a and put it at the top of b.
*/

void	pa(t_list **a, t_list **b)
{
	pb(b, a);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a == 0)
		return ;
	tmp = *a;
	(*a)->prev->next = (*a)->next;
	(*a)->next->prev = (*a)->prev;
	*a = (*a)->next;
	if ((*a)->next == *a)
		*a = 0;
	ft_lstadd_front(b, tmp);
}
