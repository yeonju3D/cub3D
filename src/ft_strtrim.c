/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:56:41 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/28 21:01:44 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_string.h"
#include <stdlib.h>

static int	ft_issep(char c, char const *sep)
{
	while (*sep)
	{
		if (*sep == c)
			return (1);
		sep++;
	}
	return (0);
}

static int	valid_check(size_t *start, size_t *end, char const *s1, \
		char const *set)
{
	while (s1[*start] && ft_issep(s1[*start], set))
		(*start)++;
	if (*start == ft_strlen(s1))
		return (0);
	while (*end >= 0 && ft_issep(s1[*end], set))
		(*end)--;
	if (*end < 0)
		(*end)++;
	return (1);
}

static char	*empty_string(void)
{
	char	*result;

	result = malloc(sizeof(char));
	if (result == NULL)
		return (NULL);
	*result = '\0';
	return (result);
}

static char	*fill_result(size_t start, size_t end, char *result, char const *s1)
{
	size_t	index;

	index = 0;
	while (start + index <= end)
	{
		result[index] = s1[start + index];
		index++;
	}
	result[index] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!valid_check(&start, &end, s1, set))
		return (empty_string());
	result = malloc(sizeof(char) * (end - start + 2));
	if (result == NULL)
		return (NULL);
	return (fill_result(start, end, result, s1));
}
