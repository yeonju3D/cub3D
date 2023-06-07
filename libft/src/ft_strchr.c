/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:23:36 by yeongo            #+#    #+#             */
/*   Updated: 2022/07/07 16:02:46 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	const char	*tmp_s;
	char		tmp_c;

	tmp_s = (char *)s;
	tmp_c = (char)c;
	while (*tmp_s)
	{
		if (*tmp_s == tmp_c)
			return ((char *)tmp_s);
		tmp_s++;
	}
	if (tmp_c == '\0')
		return ((char *)tmp_s);
	return (NULL);
}
