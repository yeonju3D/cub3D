/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:44:24 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 10:16:40 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	draw_background(t_cub3d *cub3d)
{
	t_img *const	simg = &cub3d->img;
	char			*pixel;
	int				i;
	int				j;

	j = 0;
	while (j < WIN_WIDTH)
	{
		pixel = simg->addr + j * (simg->bpp / 8);
		i = 0;
		while (i < WIN_HEIGHT / 2)
		{
			*(unsigned int *)pixel = cub3d->map.color[CEILING];
			pixel += simg->len;
			++i;
		}
		while (i < WIN_HEIGHT)
		{
			*(unsigned int *)pixel = cub3d->map.color[FLOOR];
			pixel += simg->len;
			++i;
		}
		++j;
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
		
// 		j = draw->draw_start - 1;
// 		set_wall_texture(cub3d);
// 		while (j < draw->draw_end)
// 		{
// 			draw->tex.y = (int)draw->tex_pos & (TEX_HEI - 1);
// 			draw->tex_pos += draw->step;
// 			draw->color = *(unsigned int *)(map->img[draw->wall_idx].addr
// 					+ (draw->tex. * map->img[draw->wall_idx].len
// 						+ draw->tex.j * map->img[draw->wall_idx].bpp / 8));
// 			pixel = img->addr + j * img->len + i * (img->bpp / 8);
// 			*(unsigned int *)pixel = draw->color;
// 		}
// 	}
// }

void	render(t_cub3d *cub3d)
{
	draw_background(cub3d);
	// draw_wall(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.pixel, 0, 0);
}
