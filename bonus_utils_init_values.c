/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_init_values.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:01:31 by minylee           #+#    #+#             */
/*   Updated: 2023/04/20 15:40:34 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	print_error_and_exit(void);
static void	check_errors(int argc, char *argv[]);
static void	check_duplicated_values(int argc, char *argv[]);
static void	check_wrong_value(int argc, char *argv[]);

int	init_values(t_list **a, t_list **b, int argc, char *argv[])
{
	int	idx;
	int	sign;
	int	atoi;

	if (argc == 1)
		exit(0);
	check_errors(argc, argv);
	*a = 0;
	*b = 0;
	idx = 0;
	while (++idx < argc)
	{
		atoi = ft_atoi(argv[idx], &sign);
		if ((sign < 0 && atoi > 0) || (sign > 0 && atoi < 0) || atoi == 0)
			ft_lstadd_back(a, ft_lstnew(atoi));
		else
			print_error_and_exit();
	}
	return (1);
}

static void	check_errors(int argc, char *argv[])
{
	check_duplicated_values(argc, argv);
	check_wrong_value(argc, argv);
}

static void	check_wrong_value(int argc, char *argv[])
{
	int	idx;
	int	idx2;
	int	strlen;

	idx = 0;
	while (++idx < argc)
	{
		idx2 = 1;
		strlen = ft_strlen(argv[idx]);
		if (strlen == 0)
			print_error_and_exit();
		if (!(argv[idx][0] == '+' || argv[idx][0] == '-'))
			if (!(argv[idx][0] >= '0' && argv[idx][0] <= '9'))
				print_error_and_exit();
		while (idx2 < strlen)
		{
			if (!(argv[idx][idx2] >= '0' && argv[idx][idx2] <= '9'))
				print_error_and_exit();
			idx2 += 1;
		}
	}
}

static void	check_duplicated_values(int argc, char *argv[])
{
	int	idx;
	int	idx2;
	int	strlen;

	idx = 0;
	while (++idx < argc)
	{
		idx2 = idx + 1;
		while (idx2 < argc)
		{
			strlen = ft_strlen(argv[idx]);
			if (strlen == ft_strlen(argv[idx2]))
				if (ft_strncmp(argv[idx], argv[idx2], strlen) == 0)
					print_error_and_exit();
			idx2 += 1;
		}
	}
}

static void	print_error_and_exit(void)
{
	write(1, "ERROR\n", 6);
	exit(-1);
}
