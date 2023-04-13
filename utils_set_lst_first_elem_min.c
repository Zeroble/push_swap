/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_set_lst_first_elem_min.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:49:46 by minylee           #+#    #+#             */
/*   Updated: 2023/04/14 03:59:25 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static long long int	find_min(t_list *lst)
{
	t_list		*start;
	int			min;
	long long	idx;
	int			cnt;

	start = lst;
	idx = 0;
	cnt = 1;
	min = lst->content;
	lst = lst->next;
	while (start != lst)
	{
		if (lst->content < min)
		{
			min = lst->content;
			idx = cnt;
		}
		lst = lst->next;
		cnt += 1;
	}
	return (idx);
}

void	set_first_elem_min(t_list **a, int argc)
{
	int	min_pos;
	int	cnt;

	cnt = 0;
	min_pos = find_min(*a);
	if ((argc - 1) / 2 > min_pos)
	{
		while (cnt < min_pos)
		{
			ra(a);
			cnt += 1;
		}
	}
	else
	{
		while (cnt < argc - 1 - min_pos)
		{
			rra(a);
			cnt += 1;
		}
	}
}
