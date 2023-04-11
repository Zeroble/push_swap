/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:41:19 by minylee           #+#    #+#             */
/*   Updated: 2023/04/11 13:30:02 by minylee          ###   ########.fr       */
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

int main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	init_values(&a, &b, argc, argv);
	set_first_elem_min(&a, argc);
	max_select(&a, &b, a, argc);
	printf("<- greedy sort ->\n");
	greedy_sort(&a, &b);
	printf("-----------\n");
	ft_lst_readall(a);
	printf("-----------\n");
	ft_lst_readall(b);
}

int	greedy_sort(t_list **a, t_list **b)
{
	int		b_size;
	t_move	*moves;

	b_size = ft_lstsize(*b);
	moves = malloc(sizeof(t_move) * b_size);
	printf("best score : %d!!\n", find_greedy_picks(*a, *b, moves, b_size));
	for (int i = 0 ; i < b_size ; i++)
	{
		printf("%d\t-> %d\n", i, moves[i].score);
	}
	// while (*b != 0)
	// {
	// 	moves = malloc(sizeof(t_move) * b_size);
	// 	find_greedy_picks(*a, *b, moves, b_size);
	// 	pa();
	// 	b_size -= 1;
	// }
	free(moves);
	return (1);
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
	calcurate_a(a, b->content, &(moves[0]), b_size);
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
		if (a->content > target)
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
