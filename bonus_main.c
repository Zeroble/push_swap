/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:14:20 by minylee           #+#    #+#             */
/*   Updated: 2023/04/20 14:41:19 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bonus.h"
#include "./push_swap.h"
#include "./memory_manager.h"

void		clear_buffer(char *buf, int size);
void		parse_command(char *buf, t_list **a, t_list **b);
static void	print_error_and_exit(char *buf, t_list **a, t_list **b);

static void	free_bonus(char *buf, t_list **a, t_list **b)
{
	free(buf);
	lst_freeall(a);
	lst_freeall(b);
}

int	main(int argc, char *argv[])
{
	char	*buf;
	int		read_size;
	t_list	*a;
	t_list	*b;

	init_values(&a, &b, argc, argv);
	buf = ft_malloc(sizeof(char) * BUFFER_SIZE);
	while (1)
	{
		clear_buffer(buf, BUFFER_SIZE);
		read_size = read(0, buf, BUFFER_SIZE);
		if (read_size == 0)
		{
			if (is_ascending(a) && ft_lstsize(a) == argc - 1)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
			break ;
		}
		if (!(read_size >= 3 && read_size <= 4))
			print_error_and_exit(buf, &a, &b);
		parse_command(buf, &a, &b);
	}
	free_bonus(buf, &a, &b);
	return (0);
}

void	parse_command(char *buf, t_list **a, t_list **b)
{
	if (ft_strncmp(buf, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(buf, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(buf, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(buf, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(buf, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(buf, "rrr\n", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(buf, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(buf, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(buf, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(buf, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(buf, "pb\n", 3) == 0)
		pb(a, b);
	else
		print_error_and_exit(buf, a, b);
}

void	clear_buffer(char *buf, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		buf[idx] = 0;
		idx += 1;
	}
}

static void	print_error_and_exit(char *buf, t_list **a, t_list **b)
{
	free_bonus(buf, a, b);
	write(1, "ERROR\n", 6);
	exit(-1);
}
