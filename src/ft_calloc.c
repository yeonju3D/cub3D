/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:47:49 by yeongo            #+#    #+#             */
/*   Updated: 2023/02/03 17:25:11 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			m_size;

	m_size = count * size;
	tmp = malloc(m_size);
	if (tmp == NULL)
		return (NULL);
	ft_memset(tmp, 0, m_size);
	return ((void *)tmp);
}
