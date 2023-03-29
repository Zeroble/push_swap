/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:06:42 by minylee           #+#    #+#             */
/*   Updated: 2023/03/28 18:06:42 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	return lst->prev;
}

void	ft_lst_readall(t_list *lst)
{
	t_list	*lstcpy;

	if (lst == 0)
	{
		printf("EMPTY LIST\n");
		return ;
	}
	lstcpy = lst;
	printf("%d\n", lst->content);
	lst = lst->next;
	while (lst != lstcpy)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
}

