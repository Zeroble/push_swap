/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:41:19 by minylee           #+#    #+#             */
/*   Updated: 2023/04/20 18:06:21 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "memory_manager.h"

void	simple_sort(t_list	**a, t_list	**b, int argc);
void	sort3_case1(t_list	**a);
void	sort3_case2(t_list	**a);

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	init_values(&a, &b, argc, argv);
	if (argc == 3)
		sa(&a);
	else if (argc <= 6)
		simple_sort(&a, &b, argc);
	else
	{
		split_push(&a, &b, a, argc);
		simple_sort(&a, &b, 4);
	}
	greedy_sort(&a, &b);
	set_first_elem_min(&a, argc);
	free_all_managed_memory();
	return (0);
}

void	simple_sort(t_list	**a, t_list	**b, int argc)
{
	int	cnt;

	cnt = 3;
	while (++cnt != argc)
		pb(a, b);
	if ((*a)->content < (*a)->next->content)
		sort3_case1(a);
	else
		sort3_case2(a);
}

void	sort3_case1(t_list	**a)
{
	if ((*a)->next->content < (*a)->next->next->content)
		return ;
	else
	{
		if ((*a)->content < (*a)->next->next->content)
			sa(a);
		else
			return ;
	}
}

void	sort3_case2(t_list	**a)
{
	if ((*a)->next->content < (*a)->next->next->content)
	{
		if ((*a)->content < (*a)->next->next->content)
			sa(a);
		else
			return ;
	}
	else
		sa(a);
}
