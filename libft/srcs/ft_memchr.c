/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:54:35 by yeongo            #+#    #+#             */
/*   Updated: 2022/07/07 16:00:08 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmp_s = (const unsigned char *)s;
	const unsigned char	tmp_c = (const unsigned char)c;

	while (n--)
	{
		if (*tmp_s == tmp_c)
			return ((void *)tmp_s);
		tmp_s++;
	}
	return (NULL);
}
