/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:13:05 by yeongo            #+#    #+#             */
/*   Updated: 2022/07/07 16:36:39 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*tmp_haystack = haystack;
	const char	*tmp_needle = needle;
	size_t		tmp_len;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		tmp_haystack = haystack;
		tmp_needle = needle;
		tmp_len = len;
		while (*tmp_haystack && *tmp_needle == *tmp_haystack && tmp_len-- > 0)
		{
			tmp_haystack++;
			tmp_needle++;
		}
		if (*tmp_needle == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
