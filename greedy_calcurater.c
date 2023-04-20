/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_calcurater.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:25:14 by minylee           #+#    #+#             */
/*   Updated: 2023/04/20 17:51:40 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	calcurate_score(t_move move)
{
	int	r_score;
	int	rr_score;

	r_score = ft_max(move.b_r, move.a_r);
	rr_score = ft_max(move.b_rr, move.a_rr);
	return (ft_min(r_score, rr_score));
}

void	calcurate_a(t_list *a, int target, t_move *move, int size)
{
	t_list	*end;
	int		cnt;

	cnt = 0;
	end = a->prev;
	while (a != end)
	{
		if (a->content > a->prev->content)
		{
			if (a->content > target && a->prev->content < target)
				break ;
		}
		else if (a->content < a->prev->content)
			if (a->content > target || a->prev->content < target)
				break ;
		cnt += 1;
		a = a->next;
	}
	move->a_r = cnt;
	move->a_rr = size - cnt;
}

void	calcurate_b(t_move *move, int idx, int b_size)
{
	if (idx == 0)
	{
		move->b_r = 0;
		move->b_rr = 0;
	}
	else
	{
		move->b_r = idx;
		move->b_rr = b_size - idx;
	}
}
