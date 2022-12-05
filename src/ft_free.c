/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:06:44 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/05 23:04:16 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free(char **ptr, int index_max)
{
	while (index_max >= 0)
	{
		free(ptr[index_max]);
		ptr[index_max] = NULL;
		index_max--;
	}
	free(ptr);
	ptr = NULL;
}
