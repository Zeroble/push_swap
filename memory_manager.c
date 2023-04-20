/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:55:18 by minylee           #+#    #+#             */
/*   Updated: 2023/04/20 14:22:17 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./memory_manager.h"

static void	memory_manager(void	*ptr, int mode);
static void	append_managed_malloc(t_memories **lst, void *ptr);
static void	free_all_managed_malloc(t_memories *lst);

void	free_all_managed_memory(void)
{
	memory_manager(0, FREE_ALL);
}

void	*managed_malloc(int size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == 0)
	{
		memory_manager(0, FREE_ALL);
		exit(-1);
	}
	else
		memory_manager(ret, APPEND);
	return (ret);
}

static void	memory_manager(void	*ptr, int mode)
{
	static t_memories	*lst;

	if (mode == FREE_ALL)
		free_all_managed_malloc(lst);
	if (mode == APPEND)
		append_managed_malloc(&lst, ptr);
	return ;
}

static void	append_managed_malloc(t_memories **lst, void *ptr)
{
	t_memories	*elem;
	t_memories	*cur;

	elem = malloc(sizeof(t_memories));
	if (elem == 0)
	{
		free(ptr);
		free_all_managed_malloc(*lst);
		exit(-1);
	}
	elem->next = 0;
	elem->ptr = ptr;
	if (*lst == 0)
		*lst = elem;
	else
	{
		cur = *lst;
		while (cur->next != 0)
			cur = cur->next;
		cur->next = elem;
	}
}

static void	free_all_managed_malloc(t_memories *lst)
{
	t_memories	*tmp;

	if (lst == 0)
		return ;
	while (lst->next != 0)
	{
		free(lst->ptr);
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	free(lst->ptr);
	free(lst);
}
