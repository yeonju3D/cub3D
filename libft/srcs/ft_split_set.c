/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:56:30 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/13 00:12:49 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"
#include <stdlib.h>

static int	ft_res_size(char const *str, char *sep)
{
	int	size;
	int	index;

	size = 0;
	index = 0;
	while (str[index] && str[index + 1])
	{
		if (!ft_issep(str[index], sep) && ft_issep(str[index + 1], sep))
			size++;
		index++;
	}
	if (str[index] && !ft_issep(str[index], sep))
		size++;
	return (size);
}

static int	ft_res_alloc(char ***result, int m_size, char const *str, char *sep)
{
	int	index;
	int	length;
	int	x;

	index = 0;
	length = 0;
	x = 0;
	while (str[index] && x < m_size)
	{
		while (str[index] && ft_issep(str[index], sep))
			index++;
		length = index;
		while (str[index] && !ft_issep(str[index], sep))
			index++;
		length = index - length;
		(*result)[x] = malloc(sizeof(char) * (length + 1));
		if ((*result)[x] == NULL)
		{
			ft_free_strings(result);
			return (0);
		}
		x++;
	}
	(*result)[x] = NULL;
	return (1);
}

static void	ft_rescpy(char **result, int m_size, char const *str, char *sep)
{
	int	index;
	int	x;
	int	y;

	index = 0;
	x = 0;
	while (str[index] && x < m_size)
	{
		y = 0;
		while (str[index] && ft_issep(str[index], sep))
			index++;
		while (str[index] && !ft_issep(str[index], sep))
		{
			result[x][y] = str[index];
			index++;
			y++;
		}
		result[x][y] = '\0';
		x++;
	}
}

char	**ft_split_set(char const *s, char *sep)
{
	char	**result;
	int		m_size;

	m_size = ft_res_size(s, sep);
	result = malloc(sizeof(char *) * (m_size + 1));
	if (result == NULL)
		return (NULL);
	if (!ft_res_alloc(&result, m_size, s, sep))
		return (NULL);
	ft_rescpy(result, m_size, s, sep);
	return (result);
}
