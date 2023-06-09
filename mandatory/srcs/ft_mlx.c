/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:49:20 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/09 18:22:18 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include <stddef.h>
#include <mlx.h>

int	ft_mlx_new_window(t_cub3d *cub3d, int size_x, int size_y)
{
	cub3d->win_ptr = mlx_new_window(cub3d->mlx_ptr, \
		size_x, size_y, P_NAME);
	if (cub3d->win_ptr == NULL)
		return (0);
	return (1);
}
