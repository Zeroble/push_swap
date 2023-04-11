/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_accending.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:06:45 by minylee           #+#    #+#             */
/*   Updated: 2023/04/11 12:06:57 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_ascending(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	a = a->next;
	while (tmp != a)
	{
		if (!(a->prev->content < a->content))
			return (-1);
		a = a->next;
	}
	return (1);
}
