/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:06:42 by minylee           #+#    #+#             */
/*   Updated: 2023/04/14 04:45:34 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	return (lst->prev);
}

int	ft_lstsize(t_list *lst)
{
	t_list		*start;
	long long	size;

	if (lst == 0)
		return (0);
	size = 1;
	start = lst;
	lst = lst->next;
	while (start != lst)
	{
		lst = lst->next;
		size += 1;
	}
	return (size);
}

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
