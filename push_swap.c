/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:41:19 by minylee           #+#    #+#             */
/*   Updated: 2023/03/27 19:41:19 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_errors();
static int compare_and_choose(t_list *a, int now);

int main(int argc, char *argv[])
{
	t_list *a;
	t_list *b;
	int cur;
	int his;

	a = 0;
	b = 0;

	if (check_errors() == -1)
		exit(-1);

	for (cur = 1; cur < argc; cur++)
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[cur])));
	}
	his = a->content;
	pb(&a, &b);
	cur = compare_and_choose(a, his);
	while (cur != 0)
	{
		if (cur == 1)
			pb(&a, &b);
		else
		{
			rra(&a);
			pb(&a, &b);
		}
		his = b->content;
		printf("his : %d\n",his);
		cur = compare_and_choose(a, his);
	}
	printf("-----------\n");
	ft_lst_readall(a);
	printf("-----------\n");
	ft_lst_readall(b);
}

static int check_errors()
{
	return (1);
}

// 두 수중에 a보다 크면서, 둘을 비교했을 때 더 작은 값을 리턴
static int compare_and_choose(t_list *a, int now)
{
	int prev;
	int next;

	prev = a->prev->content;
	next = a->content;
	printf("compare : %d %d\n", prev, next);
	if (now < prev && now < next)
	{
		if (prev < next)
			return (-1);
		else
			return (1);
	}
	else if (now < prev)
		return (-1);
	else if (now < next)
		return (1);
	else
		return (0);
}
