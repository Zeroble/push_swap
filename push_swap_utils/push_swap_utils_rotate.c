/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:49:01 by minylee           #+#    #+#             */
/*   Updated: 2023/03/27 19:49:01 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** ra - rotate a : shift up all elemets of stack a by 1
** rb - rotate b : shift up all elemets of stack b by 1
** rr - excute ra & rb all
*/

void	ra(t_list **a)
{
	*a = (*a)->next;
}

void	rb(t_list **b)
{
	ra(b);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
