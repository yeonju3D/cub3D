/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:33:10 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 05:34:14 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_string.h"
#include "../include/ft_memory.h"

int	ft_str_append(char *dst, const char *src)
{
	char	*result;

	result = ft_strjoin(dst, src);
	if (result == NULL)
		return (0);
	free(dst);
	dst = result;
	return (1);
}
