/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:44:24 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 14:00:43 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	render_background(t_cub3d *cub3d);
static void	render_wall(t_cub3d *const cub3d, t_img *img);
static void	raycasting(t_cub3d *const cub3d, double direction, t_texture *tex);

void	render(t_cub3d *cub3d)
{
	render_background(cub3d);
	render_wall(cub3d, &cub3d->img);
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
		raycasting(cub3d, cub3d->player.direction - AOF / 2 + \
			AOF * j / WIN_WIDTH, &tex);
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

static void	raycasting(t_cub3d *const cub3d, double direction, t_texture *tex)
{
	const double	lr = 0.005;
	double			i;
	double			j;
	double			di;
	double			dj;

	i = cub3d->player.pos.i;
	j = cub3d->player.pos.j;
	double c = lr * cos(direction);
	double s = lr * sin(direction);
	while (true)
	{
		i += c;
		j += s;
		if (cub3d->map.board[(int)i][(int)j] == '1')
			break ;
	}
	double dist = sqrt((i - cub3d->player.pos.i) * (i - cub3d->player.pos.i) + (j - cub3d->player.pos.j) * (j - cub3d->player.pos.j));
	di = i - (int)i;
	dj = j - (int)j;
	if (di + dj > 1 && di > dj)
	{
		tex->img = &cub3d->map.img[SOUTH];
		tex->off = (int)(dj * TEX_WID);
	}
	else if (di + dj > 1 && di <= dj)
	{
		tex->img = &cub3d->map.img[WEST];
		tex->off = (int)((1 - di) * TEX_WID);
	}
	else if (di > dj)
	{
		tex->img = &cub3d->map.img[EAST];
		tex->off = (int)(di * TEX_WID);
	}
	else
	{
		tex->img = &cub3d->map.img[NORTH];
		tex->off = (int)((1 - dj) * TEX_WID);
	}
	dist *= cos(fabs(direction - cub3d->player.direction));
	if (dist < 1)
		dist = 1;
	tex->start = (int)(0.5 * WIN_HEIGHT - 0.3 * WIN_HEIGHT / dist);
	tex->end = (int)(0.5 * WIN_HEIGHT + 0.3 * WIN_HEIGHT / dist);
}

// typedef struct s_texture
// {
// 	t_img	*img;
// 	int		off;
// 	int		start;
// 	int		end;
// }	t_texture;