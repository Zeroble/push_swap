/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:48:01 by minylee           #+#    #+#             */
/*   Updated: 2023/04/14 04:00:29 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	greedy_rotate_r(t_list **a, t_list **b, t_move move)
{
	while (move.a_r > 0 || move.b_r > 0)
	{
		if (move.a_r > 0 && move.b_r > 0)
			rr(a, b);
		else if (move.a_r > 0)
			ra(a);
		else if (move.b_r > 0)
			rb(b);
		move.a_r -= 1;
		move.b_r -= 1;
	}
}

static void	greedy_rotate_rr(t_list **a, t_list **b, t_move move)
{
	while (move.a_rr > 0 || move.b_rr > 0)
	{
		if (move.a_rr > 0 && move.b_rr > 0)
			rrr(a, b);
		else if (move.a_rr > 0)
			rra(a);
		else if (move.b_rr > 0)
			rrb(b);
		move.a_rr -= 1;
		move.b_rr -= 1;
	}
}

void	greedy_rotate(t_list **a, t_list **b, t_move move)
{
	if (ft_max(move.a_r, move.b_r) == move.score)
		greedy_rotate_r(a, b, move);
	else if (ft_max(move.a_rr, move.b_rr) == move.score)
		greedy_rotate_rr(a, b, move);
	pa(a, b);
}
