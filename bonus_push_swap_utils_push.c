/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_push_swap_utils_push.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:48:59 by minylee           #+#    #+#             */
/*   Updated: 2023/04/20 14:08:26 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a == 0)
		return ;
	else if ((*a)->next == *a)
	{
		ft_lstadd_front(b, *a);
		*a = 0;
	}
	else
	{
		tmp = *a;
		(*a)->prev->next = (*a)->next;
		(*a)->next->prev = (*a)->prev;
		*a = (*a)->next;
		ft_lstadd_front(b, tmp);
	}
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
}
