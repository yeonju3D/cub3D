/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:06:44 by yeongo            #+#    #+#             */
/*   Updated: 2023/02/03 17:25:18 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	ft_free_str(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

void	ft_free_strings(char ***strings)
{
	int	index;

	if (*strings != NULL)
	{
		index = 0;
		while ((*strings)[index] != NULL)
		{
			free((*strings)[index]);
			(*strings)[index] = NULL;
			index++;
		}
		free(*strings);
		*strings = NULL;
	}
}

void	ft_free_void(void ***ptr, int index_max)
{
	if (*ptr != NULL)
	{
		while (--index_max >= 0)
		{
			if ((*ptr)[index_max] != NULL)
				free((*ptr)[index_max]);
			(*ptr)[index_max] = NULL;
		}
		free(*ptr);
		*ptr = NULL;
	}
}
