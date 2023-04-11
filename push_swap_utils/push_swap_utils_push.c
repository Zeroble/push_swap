/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:48:59 by minylee           #+#    #+#             */
/*   Updated: 2023/04/11 12:15:15 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **a, t_list **b)
{
	pb(b, a);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a == 0)
		return ;
	tmp = *a;
	(*a)->prev->next = (*a)->next;
	(*a)->next->prev = (*a)->prev;
	*a = (*a)->next;
	if ((*a)->next == *a)
		*a = 0;
		// TODO
	ft_lstadd_front(b, tmp);
}
