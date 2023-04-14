/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:43:46 by minylee           #+#    #+#             */
/*   Updated: 2023/04/14 08:38:43 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			return ('\0');
		i++;
	}
	return ('\0');
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (1)
	{
		if (*(s + i) == '\0')
			break ;
		i++;
	}
	return (i);
}

void	*ft_malloc(size_t size)
{
	void	*mal;

	mal = malloc(size);
	if (mal == 0)
		exit(-1);
	return (mal);
}
