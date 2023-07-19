/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:44:24 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/19 11:56:57 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "raycasting.h"

static void	set_buf(t_cub3d *const cub3d);
static void	set_screen(unsigned int *buf, t_img *screen);

void	render(t_cub3d *cub3d)
{
	ft_memcpy(cub3d->buf, cub3d->bg, \
		sizeof(unsigned int) * WIN_HEIGHT * WIN_WIDTH);
	set_buf(cub3d);
	set_screen(cub3d->buf, &cub3d->screen);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->screen.pixels, 0, 0);
}

void	render_background(t_cub3d *cub3d)
{
	int	i;
	int	j;

	j = 0;
	while (j < WIN_WIDTH)
	{
		i = 0;
		while (i < WIN_HEIGHT / 2)
		{
			cub3d->bg[i * WIN_WIDTH + j] = cub3d->color[CEILING];
			++i;
		}
		while (i < WIN_HEIGHT)
		{
			cub3d->bg[i * WIN_WIDTH + j] = cub3d->color[FLOOR];
			++i;
		}
		++j;
	}
}

static void	set_buf(t_cub3d *const cub3d)
{
	int				i;
	int				j;
	unsigned int	color;
	t_texture		tex;

	j = 0;
	while (j < WIN_WIDTH)
	{
		raycasting(cub3d, cub3d->player.direction + AOF / 2 + \
			- AOF * j / WIN_WIDTH, &tex);
		i = tex.start;
		while (i <= tex.end)
		{
			if (0 <= i && i < WIN_HEIGHT)
			{
				color = *(unsigned int *)(tex.img->addr + (TEX_HEIGHT - 1) * \
					(i - tex.start) / (tex.end - tex.start) * tex.img->len + \
					tex.off * tex.img->bpp / 8);
				cub3d->buf[i * WIN_WIDTH + j] = color;
			}
			++i;
		}
		++j;
	}
}

static void	set_screen(unsigned int *buf, t_img *screen)
{
	int				i;
	int				j;
	char			*pixel;
	unsigned int	mixed;

	j = 1;
	while (j < WIN_WIDTH - 1)
	{
		i = 1;
		while (i < WIN_HEIGHT - 1)
		{
			pixel = screen->addr + i * screen->len + j * (screen->bpp / 8);
			mixed = buf[i * WIN_WIDTH + j];
			// mixed = (buf[(i - 1) * WIN_WIDTH + j] +
			// 			buf[(i + 1) * WIN_WIDTH + j] +
			// 			buf[i * WIN_WIDTH + j] +
			// 			buf[i * WIN_WIDTH + j - 1] +
			// 			buf[i * WIN_WIDTH + j + 1]) / 5;
			*(unsigned int *)pixel = mixed;
			++i;
		}
		++j;
	}
}
