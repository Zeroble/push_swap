/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:42:45 by minylee           #+#    #+#             */
/*   Updated: 2023/04/14 03:59:28 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	split_push(t_list **a, t_list **b, t_list *start, int argc)
{
	int	pivot1;
	int	pivot2;

	find_pivots(*a, argc, &pivot1, &pivot2);
	ra(a);
	while ((*a) != start)
	{
		if ((*a)->content < pivot2)
		{
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
}
