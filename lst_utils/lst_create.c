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

t_list	*ft_lstnew(int num)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	if (ret == 0)
		return (0);
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
