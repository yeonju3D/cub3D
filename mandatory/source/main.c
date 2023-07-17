/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:23:18 by yeongo            #+#    #+#             */
/*   Updated: 2023/07/17 09:31:13 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "event.h"
#include "utils.h"
#include "update.h"
#include "render.h"

static void	init(t_cub3d *const cub3d);
static int	game_loop(t_cub3d *cub3d);

int	main(int argc, char *argv[])
{
	t_cub3d	cub3d;
	int		fd;

	_assert(argc == 2 && is_extension(argv[1], ".cub"), "Usage: .cub3D *.cub\n");
	fd = open(argv[1], O_RDONLY);
	_assert(fd != -1, strerror(errno));
	init(&cub3d);
	parse_texture(&cub3d, fd);
	parse_map(&cub3d, fd);
	mlx_hook(cub3d.win, ON_KEYDOWN, KEY_PRESS_MASK, key_down, &cub3d);
	mlx_hook(cub3d.win, ON_KEYUP, KEY_RELEASE_MASK, key_up, &cub3d);
	mlx_hook(cub3d.win, ON_DESTORY, BUTTON_PRESS_MASK, destroy, &cub3d);
	mlx_loop_hook(cub3d.mlx, game_loop, &cub3d);
	mlx_loop(cub3d.mlx);
	return (EXIT_SUCCESS);
}

static void	init(t_cub3d *const cub3d)
{
	t_img *const	img = &cub3d->img;

	ft_bzero(cub3d, sizeof(t_cub3d));
	cub3d->mlx = mlx_init();
	_assert(cub3d->mlx != NULL, "mlx_init() failed\n");
	cub3d->win = mlx_new_window(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT, PROGRAM);
	_assert(cub3d->win != NULL, "mlx_new_window() failed\n");
	img->pixel = mlx_new_image(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT);
	_assert(img->pixel != NULL, "mlx_new_image() failed\n");
	img->addr = mlx_get_data_addr(img->pixel, &img->bpp, \
		&img->len, &img->endian);
	_assert(img->addr != NULL, "mlx_get_data_addr() failed\n");
}

static int	game_loop(t_cub3d *cub3d)
{
	update(cub3d);
	render(cub3d);
	return (0);
}
