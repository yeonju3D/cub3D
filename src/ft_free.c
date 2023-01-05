/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:06:44 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 05:15:28 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_memory.h"

void	ft_free_str(char **str)
{
	free(*str);
	*str = NULL;
}

void	ft_free_char(char **ptr)
{
	int	index;

	index = 0;
	while (ptr[index] != NULL)
	{
		free(ptr[index]);
		ptr[index] = NULL;
		index++;
	}
	free(ptr);
	ptr = NULL;
}

void	ft_free_void(void **ptr, int index_max)
{
	while (--index_max >= 0)
	{
		if (ptr[index_max] != NULL)
			free(ptr[index_max]);
		ptr[index_max] = NULL;
	}
	free(ptr);
	ptr = NULL;
}
