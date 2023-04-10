/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:41:19 by minylee           #+#    #+#             */
/*   Updated: 2023/04/10 22:35:16 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				check_errors(t_list *a);
static int				compare_and_choose(t_list *a, int now);
static int				is_ascending(t_list *a);
static long long int	find_min(t_list *lst);
static void				init_forward(t_list **a, t_list **b);
static int	find_best_init(t_list *a, int argc, int **ret);
static int				find_best_value(t_list *start, t_list *end, int *arr);
static int				*find_path_by_result(int *arr, int argc);

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		idx;
	int		cur2;
	int		*ret;

	a = 0;
	b = 0;
	idx = 0;
	while (++idx < argc)
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[idx])));
	// if (check_errors(a) == -1)
	// 	exit(-1);
	idx = 0;
	// cur2 = find_min(a);
	// while (idx++ < cur2)
	// 	ra(&a);
	// init_forward(&a, &b);
	printf("-----------\n");
	ft_lst_readall(a);
	printf("-----------\n");
	ft_lst_readall(b);
	int best = find_best_init(a, argc, &ret);
	// printf("%d\n", ret[0]);
	for (int i = 0 ; i < best ; i++)
		printf("%d\t->\t%d\n", i, ret[i]);
}

static int	check_errors(t_list *a)
{
	if (is_ascending(a))
		return (-1);
	return (1);
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

static int	find_best_init(t_list *a, int argc, int **ret)
{
	int		*arr;
	t_list	*start;
	t_list	*idx;
	int		cnt;

	arr = malloc(sizeof(int) * (argc));
	arr[0] = 1;
	cnt = 1;
	start = a;
	a = a->next;
	arr[argc - 1] = 1;
	while (start != a)
	{
		arr[cnt] = find_best_value(start, a, arr);
		if (arr[cnt] > arr[argc - 1])
			arr[argc - 1] = arr[cnt];
		cnt += 1;
		a = a->next;
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
	printf("val to find : %d\n", val_to_find);
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
	int	ret;

	cnt = 1;
	start = start->next;
	ret = 1;
	while (start != end)
	{
		if (start->content < end->content && arr[cnt] > ret)
			ret = arr[cnt];
		start = start->next;
		cnt += 1;
	}
	return (ret + 1);
}
