/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:33:10 by yeongo            #+#    #+#             */
/*   Updated: 2023/04/21 21:40:34 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

int	ft_strapp_front(const char *src, char **dst)
{
	char	*result;

	result = ft_strjoin(src, *dst);
	if (result == NULL)
		return (0);
	free(*dst);
	*dst = result;
	return (1);
}

int	ft_strapp_back(char **dst, const char *src)
{
	char	*result;

	result = ft_strjoin(*dst, src);
	if (result == NULL)
		return (0);
	free(*dst);
	*dst = result;
	return (1);
}
