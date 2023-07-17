/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:19:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 19:25:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

static void	move(const char **board, t_pos *const pos, double direction)
{
	const double	i = pos->i + cos(direction) * MV_SPEED;
	const double	j = pos->j + sin(direction) * MV_SPEED;

	if (board[(int)i][(int)pos->j] != '1' && board[(int)pos->i][(int)j] != '1')
	{
		pos->i = i;
		pos->j = j;
	}
}

void	update(t_cub3d *cub3d)
{
	double	direction;

	direction = -1.0f;
	if (cub3d->key == KEY_W)
		direction = cub3d->player.direction + 0 * M_PI / 2;
	else if (cub3d->key == KEY_D)
		direction = cub3d->player.direction + 1 * M_PI / 2;
	else if (cub3d->key == KEY_S)
		direction = cub3d->player.direction + 2 * M_PI / 2;
	else if (cub3d->key == KEY_A)
		direction = cub3d->player.direction + 3 * M_PI / 2;
	if (direction > 0)
	{
		move((const char **)cub3d->map.board, &cub3d->player.pos, direction);
		return ;
	}
	if (cub3d->key == KEY_LEFT)
		cub3d->player.direction -= RT_SPEED;
	else if (cub3d->key == KEY_RIGHT)
		cub3d->player.direction += RT_SPEED;
	if (cub3d->player.direction > 2 * M_PI)
		cub3d->player.direction -= 2 * M_PI;
	else if (cub3d->player.direction < 0)
		cub3d->player.direction += 2 * M_PI;
}
