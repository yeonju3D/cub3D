/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:52:42 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 06:24:27 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/**
 * @brief 
 * Calculates the length of the string pointed to by s,
 * excluding the terminating null byte ('\0').
 * @param s 
 * @return The number of bytes in the string pointed to by s.
 */
size_t	ft_strlen(const char *s)
{
	const char	*ptr = s;

	if (s == NULL)
		return (0);
	while (*ptr != '\0')
		++ptr;
	return (ptr - s);
}
