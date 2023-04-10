/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:41:19 by minylee           #+#    #+#             */
/*   Updated: 2023/04/11 01:35:47 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				compare_and_choose(t_list *a, int now);
static int				is_ascending(t_list *a);
static long long int	find_min(t_list *lst);
static void				init_forward(t_list **a, t_list **b);
static int	find_best_init(t_list *a, int argc, int **ret);
static int				find_best_value(t_list *start, t_list *end, int *arr);
static int				*find_path_by_result(int *arr, int argc);
static void	bubblesort(int *arr, int n);
static int	find_mid_value(t_list *a, int argc);

static void	step_one(t_list **a, t_list **b, t_list *start, int argc)
{
	int	*best_picks;
	int	best_cnt;
	int	best_cur;
	int	cnt;
	int	ra_before;

	best_cnt = find_best_init(*a, argc, &best_picks);
	// printf("==========best picks=========\n");
	// for (int i = 0 ; i < best_cnt ; i++)
	// 	printf("%d\t-> %d\n", i, best_picks[i]);
	// printf("==========best picks=========\n");
	best_cur = 1;
	cnt = 1;
	ra(a);
	ra_before = 1;
	while ((*a) != start)
	{
		printf("next best : %d\tnow count : %d\n", best_picks[best_cur], cnt);
		if (best_picks[best_cur] == cnt && best_cur != best_cnt)
		{
			ra(a);
			best_cur += 1;
		}
		else
			pb(a, b);
		cnt += 1;
	}
	free(best_picks);
}

static int	init_and_add_values(t_list **a, t_list **b, int argc, char **argv)
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

static void	step_zero(t_list **a, int argc)
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

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	init_and_add_values(&a, &b, argc, argv);
	step_zero(&a, argc);
	printf("-----------\n");
	ft_lst_readall(a);
	printf("-----------\n");
	ft_lst_readall(b);
	step_one(&a, &b, a, argc);
	printf("mid : %d\n", find_mid_value(a, argc));
	printf("-----------\n");
	ft_lst_readall(a);
	printf("-----------\n");
	ft_lst_readall(b);
}

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

static int	is_ascending(t_list *a)
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

static int	find_best_init(t_list *cur, int argc, int **ret)
{
	int		*arr;
	t_list	*start;
	t_list	*idx;
	int		cnt;

	arr = malloc(sizeof(int) * (argc));
	arr[0] = 1;
	cnt = 1;
	start = cur;
	cur = cur->next;
	arr[argc - 1] = 1;
	printf("first value : %d\n", start->content);
	while (start != cur)
	{
		printf("now setting arr[%d] (about %d)\n", cnt, cur->content);
		arr[cnt] = find_best_value(start, cur, arr);
		printf("set arr[%d] = %d\n", cnt, arr[cnt]);
		if (arr[cnt] > arr[argc - 1])
			arr[argc - 1] = arr[cnt];
		cnt += 1;
		cur = cur->next;
	}
	*ret = find_path_by_result(arr, argc);
	argc = arr[argc - 1];
	free(arr);
	return (argc);
}

static int	*find_path_by_result(int *arr, int argc)
{
	int	*ret;
	int	idx;
	int	val_to_find;

	idx = argc - 2;
	val_to_find = arr[argc - 1];
	for (int i = 0 ; i < argc - 1; i++)
		printf("%d\t-> %d\n", i, arr[i]);
	printf("max\t-> %d\n", arr[argc - 1]);
	ret = malloc(sizeof(int) * (arr[argc - 1]));
	while (idx != -1)
	{
		if (val_to_find == arr[idx])
		{
			ret[val_to_find - 1] = idx;
			val_to_find -= 1;
		}
		idx -= 1;
	}
	return (ret);
}

static int	find_best_value(t_list *start, t_list *end, int *arr)
{
	int	cnt;
	int	max;

	cnt = 1;
	start = start->next;
	max = 1;
	while (start != end)
	{
		if (start->content < end->content && arr[cnt] > max)
		{
			printf("change max : %d %d\n", start->content, end->content);
			max = arr[cnt];
		}
		start = start->next;
		cnt += 1;
	}
	return (max + 1);
}

static void	bubblesort(int *arr, int n)
{
	int	cur1;
	int	cur2;
	int	tmp;

	cur1 = 0;
	while (cur1 < n - 1)
	{
		cur2 = 0;
		while (cur2 < n - 1 - cur1)
		{
			if (arr[cur2] > arr[cur2 + 1])
			{
				tmp = arr[cur2];
				arr[cur2] = arr[cur2 + 1];
				arr[cur2 + 1] = tmp;
			}
			cur2 += 1;
		}
		cur1 += 1;
	}
}

static int	find_mid_value(t_list *a, int argc)
{
	int		*arr;
	t_list	*start;
	int		cnt;

	start = a;
	a = a->next;
	cnt = 1;
	arr = malloc(sizeof(int) * (argc - 1));
	arr[0] = start->content;
	while (start != a)
	{
		arr[cnt] = a->content;
		a = a->next;
		cnt += 1;
	}
	bubblesort(arr, argc - 1);
	cnt = arr[(argc - 1) / 2];
	free(arr);
	return (cnt);
}
