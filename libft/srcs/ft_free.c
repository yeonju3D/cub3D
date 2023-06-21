/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:06:44 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/21 20:52:14 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_str(char **str)
{
	free(*str);
	*str = NULL;
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
			{
				free((*ptr)[index_max]);
				(*ptr)[index_max] = NULL;
			}
		}
		free(*ptr);
		*ptr = NULL;
	}
}
