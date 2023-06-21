/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:33:10 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/21 20:59:54 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"
#include <stdbool.h>

bool	ft_strapp_front(const char *src, char **dst)
{
	char	*result;

	result = ft_strjoin(src, *dst);
	if (result == NULL)
		return (false);
	free(*dst);
	*dst = result;
	return (true);
}

bool	ft_strapp_back(char **dst, const char *src)
{
	char	*result;

	result = ft_strjoin(*dst, src);
	if (result == NULL)
		return (false);
	free(*dst);
	*dst = result;
	return (true);
}
