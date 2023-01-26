/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:37:08 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/20 12:54:03 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_string.h"
#include "../include/ft_memory.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_memmove(result, s1, s1_len);
	ft_memmove(result + s1_len, s2, s2_len);
	return (result);
}
