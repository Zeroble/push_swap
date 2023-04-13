/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:42:45 by minylee           #+#    #+#             */
/*   Updated: 2023/04/13 23:57:09 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		max_select(t_list **a, t_list **b, t_list *start, int argc);
static int	find_best_picks(t_list *cur, int argc, int **ret);
static int	find_best_pick(t_list *start, t_list *end, int *arr);
static int	*find_path_by_result(int *arr, int argc);

void	max_select(t_list **a, t_list **b, t_list *start, int argc)
{
	int	pivot1;
	int	pivot2;

	find_pivots(*a, argc, &pivot1, &pivot2);
	// printf("pivots : %d %d\n", pivot1, pivot2);
	ra(a);
	while ((*a) != start)
	{
		if ((*a)->content < pivot2)
		{
			// printf("under pivot2 : %d\n", (*a)->content);
			pb(a, b);
			if ((*b)->content < pivot1)
				rb(b);
		}
		else
			ra(a);
	}
	ra(a);
	while ((*a) != start)
	{
		if ((*a)->prev->content > (*a)->content)
			pb(a, b);
		else
			ra(a);
	}
	// printf("-----------\n");
	// ft_lst_readall(*a);
	// printf("-----------\n");
	// ft_lst_readall(*b);
}

static int	find_best_picks(t_list *cur, int argc, int **ret)
{
	int		*arr;
	t_list	*start;
	t_list	*idx;
	int		cnt;

	arr = malloc(sizeof(int) * (argc));
	arr[0] = 1;
	cnt = 1;
	start = cur;
	cur = cur->next;
	arr[argc - 1] = 1;
	while (start != cur)
	{
		arr[cnt] = find_best_pick(start, cur, arr);
		if (arr[cnt] > arr[argc - 1])
			arr[argc - 1] = arr[cnt];
		cnt += 1;
		cur = cur->next;
	}
	*ret = find_path_by_result(arr, argc);
	argc = arr[argc - 1];
	free(arr);
	return (argc);
}

static int	find_best_pick(t_list *start, t_list *end, int *arr)
{
	int	cnt;
	int	max;

	cnt = 1;
	start = start->next;
	max = 1;
	while (start != end)
	{
		if (start->content < end->content && arr[cnt] > max)
		{
			// printf("change max : %d %d\n", start->content, end->content);
			max = arr[cnt];
		}
		start = start->next;
		cnt += 1;
	}
	return (max + 1);
}

static int	*find_path_by_result(int *arr, int argc)
{
	int	*ret;
	int	idx;
	int	val_to_find;

	idx = argc - 2;
	val_to_find = arr[argc - 1];
	// for (int i = 0 ; i < argc - 1; i++)
	// 	printf("%d\t-> %d\n", i, arr[i]);
	// printf("max\t-> %d\n", arr[argc - 1]);
	ret = malloc(sizeof(int) * (arr[argc - 1]));
	while (idx != -1)
	{
		if (val_to_find == arr[idx])
		{
			ret[val_to_find - 1] = idx;
			val_to_find -= 1;
		}
		idx -= 1;
	}
	return (ret);
}
