/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:41:19 by minylee           #+#    #+#             */
/*   Updated: 2023/04/13 17:48:25 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 100 ->700
// 500 -> 5500
void	calcurate_a(t_list *a, int target, t_move *move, int size);
int	find_greedy_picks(t_list *a, t_list *b, t_move *moves, int b_size);
int	greedy_sort(t_list **a, t_list **b);
void	calcurate_b(t_move *move, int idx, int b_size);
int	calcurate_score(t_move move);
void	greedy_rotate(t_list **a, t_list **b, t_move move);

int main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	// printf("init values \n");
	init_values(&a, &b, argc, argv);
	// printf("set first elem min\n");
	set_first_elem_min(&a, argc);
	// printf("max select\n");
	max_select(&a, &b, a, argc);
	// printf("greedy sort\n");
	greedy_sort(&a, &b);
	// printf("set first elem min2\n");
	set_first_elem_min(&a, argc);
	// printf("-----------\n");
	// ft_lst_readall(a);
	// printf("-----------\n");
	// ft_lst_readall(b);
}

int	greedy_sort(t_list **a, t_list **b)
{
	int		b_size;
	t_move	*moves;
	int		best_score;

	b_size = ft_lstsize(*b);
	for (;b_size > 0; b_size -= 1)
	{
		moves = malloc(sizeof(t_move) * b_size);
		best_score = find_greedy_picks(*a, *b, moves, b_size);
		for (int i = 0 ; i < b_size ; i++)
		{
			if (best_score == moves[i].score)
			{
				greedy_rotate(a, b, moves[i]);
				break ;
			}
		}
		free(moves);
	}
	return (1);
}

void	greedy_rotate(t_list **a, t_list **b, t_move move)
{
	if (ft_max(move.a_r, move.b_r) == move.score)
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
	else if (ft_max(move.a_rr, move.b_rr) == move.score)
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
	pa(a, b);
}

int	find_greedy_picks(t_list *a, t_list *b, t_move *moves, int b_size)
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
		if (a->content > target && a->prev->content < target)
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
