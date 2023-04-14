/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:09:27 by minylee           #+#    #+#             */
/*   Updated: 2023/04/14 08:59:52 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

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
		free(tmp);
	}
	free(*lst);
	*lst = 0;
}
