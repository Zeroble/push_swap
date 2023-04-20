/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:47:45 by minylee           #+#    #+#             */
/*   Updated: 2023/04/20 14:20:28 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	find_greedy_picks(t_list *a, t_list *b, t_move *moves, int b_size);

int	greedy_sort(t_list **a, t_list **b)
{
	int		b_size;
	t_move	*moves;
	int		best_score;
	int		cur;

	b_size = ft_lstsize(*b);
	while (b_size > 0)
	{
		moves = ft_malloc(sizeof(t_move) * b_size);
		best_score = find_greedy_picks(*a, *b, moves, b_size);
		cur = 0;
		while (cur < b_size)
		{
			if (best_score == moves[cur].score)
			{
				greedy_rotate(a, b, moves[cur]);
				break ;
			}
			cur += 1;
		}
		free(moves);
		b_size -= 1;
	}
	return (1);
}

static int	find_greedy_picks(t_list *a, t_list *b, t_move *moves, int b_size)
{
	t_list	*end;
	int		idx;
	int		a_size;
	int		best_score;

	end = b;
	idx = 1;
	a_size = ft_lstsize(a);
	calcurate_a(a, b->content, &(moves[0]), a_size);
	calcurate_b(&(moves[0]), 0, b_size);
	moves[0].score = calcurate_score(moves[0]);
	best_score = moves[0].score;
	b = b->next;
	while (b != end)
	{
		calcurate_a(a, b->content, &(moves[idx]), a_size);
		calcurate_b(&(moves[idx]), idx, b_size);
		moves[idx].score = calcurate_score(moves[idx]);
		if (moves[idx].score < best_score)
			best_score = moves[idx].score;
		b = b->next;
		idx += 1;
	}
	return (best_score);
}
