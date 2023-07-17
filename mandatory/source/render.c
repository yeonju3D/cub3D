/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:44:24 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 09:31:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	draw_background(t_cub3d *cub3d)
{
	t_img *const	simg = &cub3d->img;
	char			*pixel;
	int				i;
	int				j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		pixel = simg->addr + i * (simg->bpp / 8);
		j = 0;
		while (j < WIN_HEIGHT / 2)
		{
			*(unsigned int *)pixel = cub3d->map.color[CEILING];
			pixel += simg->len;
			++j;
		}
		while (j < WIN_HEIGHT)
		{
			*(unsigned int *)pixel = cub3d->map.color[FLOOR];
			pixel += simg->len;
			++j;
		}
		++i;
	}
}

// static void	draw_wall(t_cub3d *const cub3d)
// {
// 	int				i;
// 	int				j;
// 	char			*pixel;
// 	t_img *const	img = &cub3d->img;

// 	i = 0;
// 	while (i < WIN_WIDTH)
// 	{
// 		set_vector(vec, i);
// 		dda(cub3d, vec, draw);
// 		if ((vec->side == 0 && vec->ray_dir.x > 0) || (vec->side == 1 && vec->ray_dir.y < 0))
// 			draw->tex.x = TEX_WID - draw->tex.x - 1;
// 		j = draw->draw_start - 1;
// 		set_wall_texture(cub3d);
// 		while (j < draw->draw_end)
// 		{
// 			draw->tex.y = (int)draw->tex_pos & (TEX_HEI - 1);
// 			draw->tex_pos += draw->step;
// 			draw->color = *(unsigned int *)(map->img[draw->wall_idx].addr
// 					+ (draw->tex.y * map->img[draw->wall_idx].len
// 						+ draw->tex.x * map->img[draw->wall_idx].bpp / 8));
// 			pixel = cub3d->img.addr + j * cub3d->img.len + i * (cub3d->img.bpp / 8);
// 			*(unsigned int *)dst = draw->color;
// 		}
// 	}
// }

void	render(t_cub3d *cub3d)
{
	draw_background(cub3d);
	// draw_wall(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.pixel, 0, 0);
}
