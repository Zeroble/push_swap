/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:41:19 by minylee           #+#    #+#             */
/*   Updated: 2023/04/20 14:44:23 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "memory_manager.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	init_values(&a, &b, argc, argv);
	split_push(&a, &b, a, argc);
	greedy_sort(&a, &b);
	set_first_elem_min(&a, argc);
	free_all_managed_memory();
	return (0);
}
