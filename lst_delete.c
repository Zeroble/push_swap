/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:09:27 by minylee           #+#    #+#             */
/*   Updated: 2023/04/14 03:59:41 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	lst_freeall(t_list **lst)
{
	t_list	*tmp;

	if (*lst == 0)
		return ;
	(*lst)->prev->next = 0;
	while ((*lst)->next != 0)
	{
		tmp = *lst;
		*lst = (*lst)->next;
	}
	free(*lst);
	*lst = 0;
}
