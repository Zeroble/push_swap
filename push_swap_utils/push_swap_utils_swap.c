/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:02:03 by minylee           #+#    #+#             */
/*   Updated: 2023/04/13 17:40:42 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** sa - swap a
** sb - swap b
** ss - sa & sb
*/

void	sa(t_list **a)
{
	int	tmp;

	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	// write(1, "pb\n", 3);
}

void	sb(t_list **b)
{
	sa(b);
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sa(b);
}
