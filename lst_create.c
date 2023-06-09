/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:06:42 by minylee           #+#    #+#             */
/*   Updated: 2023/04/20 14:23:09 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./memory_manager.h"

t_list	*ft_lstnew(int num)
{
	t_list	*ret;

	ret = managed_malloc(sizeof(t_list));
	ret->content = num;
	ret->next = ret;
	ret->prev = ret;
	return (ret);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == 0)
	{
		new->next = new;
		new->prev = new;
		*lst = new;
		return ;
	}
	(*lst)->prev->next = new;
	new->prev = (*lst)->prev;
	new->next = *lst;
	(*lst)->prev = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	ft_lstadd_back(lst, new);
	*lst = new;
}
