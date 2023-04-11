/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:01:31 by minylee           #+#    #+#             */
/*   Updated: 2023/04/11 12:03:54 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	init_values(t_list **a, t_list **b, int argc, char **argv)
{
	int	idx;

	*a = 0;
	*b = 0;
	idx = 0;
	while (++idx < argc)
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[idx])));
	if (is_ascending(*a) == 1)
		return (-1);
	return (1);
}
