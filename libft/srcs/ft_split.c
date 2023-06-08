/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:56:30 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/21 12:35:24 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	free_all(char **result, int max_index)
{
	int	index;

	index = 0;
	while (index < max_index)
	{
		free(result[index]);
		index++;
	}
	return (0);
}

int	ft_res_size(char const *str, char sep)
{
	int	size;
	int	index;

	size = 0;
	index = 0;
	while (str[index] && str[index + 1])
	{
		if (str[index] != sep && str[index + 1] == sep)
			size++;
		index++;
	}
	if (str[index] && str[index] != sep)
		size++;
	return (size);
}

static int	ft_res_alloc(char **result, int res_size, char const *str, char sep)
{
	int	index;
	int	length;
	int	x;

	index = 0;
	length = 0;
	x = 0;
	while (str[index] && x < res_size)
	{
		while (str[index] && str[index] == sep)
			index++;
		while (str[index] && str[index] != sep)
		{
			length++;
			index++;
		}
		result[x] = malloc(sizeof(char) * (length + 1));
		if (result[x] == NULL)
			return (free_all(result, x));
		x++;
	}
	result[x] = NULL;
	return (1);
}

static void	ft_rescpy(char **result, int res_size, char const *str, char sep)
{
	int	index;
	int	x;
	int	y;

	index = 0;
	x = 0;
	while (str[index] && x < res_size)
	{
		y = 0;
		while (str[index] && str[index] == sep)
			index++;
		while (str[index] && str[index] != sep)
		{
			result[x][y] = str[index];
			index++;
			y++;
		}
		result[x][y] = '\0';
		x++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		m_size;

	m_size = ft_res_size(s, c);
	result = malloc(sizeof(char *) * (m_size + 1));
	if (result == NULL)
		return (NULL);
	if (!ft_res_alloc(result, m_size, s, c))
	{
		free(result);
		return (NULL);
	}
	ft_rescpy(result, m_size, s, c);
	return (result);
}
