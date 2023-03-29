/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_reverse_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:55:51 by minylee           #+#    #+#             */
/*   Updated: 2023/03/27 22:55:51 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** rra - reverse rotate a : shift down all elemets of stack a by 1
** rrb - reverse rotate b : shift down all elemets of stack b by 1
** rrr - excute rra & rrb all
*/

void	rra(t_list **a)
{
	*a = (*a)->prev;
}

void	rrb(t_list **b)
{
	rra(b);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
