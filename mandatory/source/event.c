/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:57:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 19:50:02 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int	key_down(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_ESC)
		destroy(cub3d);
	else
		cub3d->key = keycode;
	return (0);
}

int	key_up(int keycode, t_cub3d *cub3d)
{
	if (cub3d->key == (t_key)keycode)
		cub3d->key = KEY_RELESED;
	return (0);
}

int	destroy(t_cub3d *cub3d)
{
	int	i;

	mlx_destroy_image(cub3d->mlx, cub3d->screen.pixels);
	mlx_destroy_image(cub3d->mlx, cub3d->img[NORTH].pixels);
	mlx_destroy_image(cub3d->mlx, cub3d->img[SOUTH].pixels);
	mlx_destroy_image(cub3d->mlx, cub3d->img[WEST].pixels);
	mlx_destroy_image(cub3d->mlx, cub3d->img[EAST].pixels);
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	i = 0;
	while (i < cub3d->map.size)
		free(cub3d->map.board[i++]);
	free(cub3d->map.board);
	exit(EXIT_SUCCESS);
	return (0);
}
