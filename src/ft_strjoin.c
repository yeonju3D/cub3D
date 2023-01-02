/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:37:08 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/28 21:00:49 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_string.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	m_size;
	size_t	index;

	m_size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (m_size + 1));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (s1 && *s1)
	{
		result[index] = *s1;
		index++;
		s1++;
	}
	while (s2 && *s2)
	{
		result[index] = *s2;
		index++;
		s2++;
	}
	result[index] = '\0';
	return (result);
}
