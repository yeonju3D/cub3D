/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:44:24 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 11:28:08 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	render_background(t_cub3d *cub3d);
static void	render_wall(t_cub3d *const cub3d, t_img *img);
static void	raycasting(t_cub3d *cub3d, t_texture *tex, int j);

void	render(t_cub3d *cub3d)
{
	render_background(cub3d);
	render_wall(cub3d, &cub3d->img);
	// printf("x: %f y: %f direction: %f\n", cub3d->player.pos.x, cub3d->player.pos.y, cub3d->player.direction);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.pixel, 0, 0);
}

static void	render_background(t_cub3d *cub3d)
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


static void	render_wall(t_cub3d *const cub3d, t_img *img)
{
	int			i;
	int			j;
	int			color;
	char		*pixel;
	t_texture	tex;

	j = 0;
	while (j < WIN_WIDTH)
	{
		raycasting(cub3d, &tex, j);
		i = tex.start;
		while (i <= tex.end)
		{
			color = *(unsigned int *)(tex.img->addr + \
				(TEX_HEI - 1) * (i - tex.start) / (tex.end - tex.start) * \
				tex.img->len + tex.off * tex.img->bpp / 8);
			pixel = img->addr + i * img->len + j * (img->bpp / 8);
			*(unsigned int *)pixel = color;
			++i;
		}
		++j;
	}
}

static void	raycasting(t_cub3d *cub3d, t_texture *tex, int j)
{
	const double	direction = cub3d->player.direction - AOF / 2 + \
		AOF * j / WIN_WIDTH;

	(void)direction;

	tex->img = &cub3d->map.img[NORTH];
	tex->off = 1;
	tex->start = 300;
	tex->end = 1000;
}

// typedef struct s_texture
// {
// 	t_img	*img;
// 	int		off;
// 	int		start;
// 	int		end;
// }	t_texture;