/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_reverse_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:55:51 by minylee           #+#    #+#             */
/*   Updated: 2023/04/14 07:42:22 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	reverse_rotate(t_list **a)
{
	if (*a == 0)
		return ;
	*a = (*a)->prev;
}

void	rra(t_list **a)
{
	write(1, "rra\n", 4);
	reverse_rotate(a);
}

void	rrb(t_list **b)
{
	write(1, "rrb\n", 4);
	reverse_rotate(b);
}

void	rrr(t_list **a, t_list **b)
{
	write(1, "rrr\n", 4);
	reverse_rotate(a);
	reverse_rotate(b);
}
