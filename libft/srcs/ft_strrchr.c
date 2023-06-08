/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:23:36 by yeongo            #+#    #+#             */
/*   Updated: 2022/07/07 16:04:04 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp_s = s;
	const char	tmp_c = c;

	while (*tmp_s)
		tmp_s++;
	if (tmp_c == '\0')
		return ((char *)tmp_s);
	while (tmp_s != s)
	{
		tmp_s--;
		if (*tmp_s == tmp_c)
			return ((char *)tmp_s);
	}
	return (NULL);
}
