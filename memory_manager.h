/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 05:12:02 by minylee           #+#    #+#             */
/*   Updated: 2023/04/20 10:55:58 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_MANAGER_H
# define MEMORY_MANAGER_H

# include <stdlib.h>

typedef struct s_memories
{
	struct s_memories	*next;
	void				*ptr;
}	t_memories;

enum	e_manager_mode{
	FREE_ALL,
	APPEND
};

void	*managed_malloc(int size);
void	free_all_managed_memory(void);

#endif
