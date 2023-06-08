/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:06:06 by yeongo            #+#    #+#             */
/*   Updated: 2023/04/21 21:42:09 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	m_size;
	unsigned int	idx_sub;
	char			*sub_s;

	m_size = ft_strlen(s);
	if (m_size <= start)
	{
		sub_s = malloc(sizeof(char));
		*sub_s = '\0';
		return (sub_s);
	}
	m_size -= start;
	if (m_size > len)
		m_size = len;
	sub_s = malloc(sizeof(char) * (m_size + 1));
	if (sub_s == NULL)
		return (NULL);
	idx_sub = 0;
	while (s[start + idx_sub] && idx_sub < m_size)
	{
		sub_s[idx_sub] = s[start + idx_sub];
		idx_sub++;
	}
	sub_s[idx_sub] = '\0';
	return (sub_s);
}
