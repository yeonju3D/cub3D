/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:44:35 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/19 11:59:17 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	set_image_and_off(t_cub3d *const cub3d, t_texture *tex, \
	const double di, const double dj);

void	raycasting(t_cub3d *const cub3d, double direction, t_texture *tex)
{
	double			i;
	double			j;
	double			dist;
	const double	c = LR * cos(direction);
	const double	s = LR * sin(direction);

	i = cub3d->player.pos.i;
	j = cub3d->player.pos.j;
	while (true)
	{
		i += c;
		j += s;
		if (cub3d->map.board[(int)i][(int)j] == '1')
			break ;
	}
	dist = sqrt((i - cub3d->player.pos.i) * (i - cub3d->player.pos.i) + \
				(j - cub3d->player.pos.j) * (j - cub3d->player.pos.j));
	dist *= cos(direction - cub3d->player.direction);
	tex->start = (int)(0.5 * WIN_HEIGHT - 0.5 * WIN_HEIGHT / dist);
	tex->end = (int)(0.5 * WIN_HEIGHT + 0.5 * WIN_HEIGHT / dist);
	set_image_and_off(cub3d, tex, i - (int)i, j - (int)j);
}

static void	set_image_and_off(t_cub3d *const cub3d, t_texture *tex, \
	const double di, const double dj)
{
	if (di + dj > 1 && di > dj)
	{
		tex->img = &cub3d->img[NORTH];
		tex->off = (int)(dj * TEX_WIDTH);
	}
	else if (di + dj > 1 && di <= dj)
	{
		tex->img = &cub3d->img[WEST];
		tex->off = (int)((1 - di) * TEX_WIDTH);
	}
	else if (di > dj)
	{
		tex->img = &cub3d->img[EAST];
		tex->off = (int)(di * TEX_WIDTH);
	}
	else
	{
		tex->img = &cub3d->img[SOUTH];
		tex->off = (int)((1 - dj) * TEX_WIDTH);
	}
}
