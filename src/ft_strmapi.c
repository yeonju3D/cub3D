/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:55:37 by yeongo            #+#    #+#             */
/*   Updated: 2023/04/21 21:41:56 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp_s;
	size_t			m_size;
	unsigned int	index;

	m_size = ft_strlen(s);
	tmp_s = malloc(sizeof(char) * (m_size + 1));
	if (tmp_s == NULL)
		return (NULL);
	index = 0;
	while (index < m_size)
	{
		tmp_s[index] = f(index, s[index]);
		index++;
	}
	tmp_s[index] = '\0';
	return (tmp_s);
}
