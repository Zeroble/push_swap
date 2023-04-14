/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pivot_finder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:43:41 by minylee           #+#    #+#             */
/*   Updated: 2023/04/14 08:32:04 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	bubblesort(int *arr, int n)
{
	int	cur1;
	int	cur2;
	int	tmp;

	cur1 = 0;
	while (cur1 < n - 1)
	{
		cur2 = 0;
		while (cur2 < n - 1 - cur1)
		{
			if (arr[cur2] > arr[cur2 + 1])
			{
				tmp = arr[cur2];
				arr[cur2] = arr[cur2 + 1];
				arr[cur2 + 1] = tmp;
			}
			cur2 += 1;
		}
		cur1 += 1;
	}
}

void	find_pivots(t_list *a, int argc, int *pivot1, int *pivot2)
{
	int		*arr;
	t_list	*start;
	int		cnt;
	int		pivot_idx;

	start = a;
	a = a->next;
	cnt = 1;
	arr = ft_malloc(sizeof(int) * (argc - 1));
	arr[0] = start->content;
	while (start != a)
	{
		arr[cnt] = a->content;
		a = a->next;
		cnt += 1;
	}
	bubblesort(arr, argc - 1);
	pivot_idx = (argc - 1) / 3;
	*pivot1 = arr[pivot_idx];
	*pivot2 = arr[pivot_idx * 2];
	free(arr);
}
