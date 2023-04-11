/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_middle_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:43:41 by minylee           #+#    #+#             */
/*   Updated: 2023/04/11 11:44:54 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	find_mid_value(t_list *a, int argc)
{
	int		*arr;
	t_list	*start;
	int		cnt;

	start = a;
	a = a->next;
	cnt = 1;
	arr = malloc(sizeof(int) * (argc - 1));
	arr[0] = start->content;
	while (start != a)
	{
		arr[cnt] = a->content;
		a = a->next;
		cnt += 1;
	}
	bubblesort(arr, argc - 1);
	cnt = arr[(argc - 1) / 2];
	free(arr);
	return (cnt);
}
