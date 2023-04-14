/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:49:01 by minylee           #+#    #+#             */
/*   Updated: 2023/04/14 07:42:27 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	rotate(t_list **a)
{
	if (*a == 0)
		return ;
	*a = (*a)->next;
}

void	ra(t_list **a)
{
	write(1, "ra\n", 3);
	rotate(a);
}

void	rb(t_list **b)
{
	write(1, "rb\n", 3);
	rotate(b);
}

void	rr(t_list **a, t_list **b)
{
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
}
