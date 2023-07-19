/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:19:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/19 11:54:04 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

static bool	move(const char **board, t_pos *const pos, double direction)
{
	const double	i = pos->i + cos(direction) * MV_SPEED;
	const double	j = pos->j + sin(direction) * MV_SPEED;
	bool			moved;

	moved = false;
	if (board[(int)i][(int)pos->j] != '1')
	{
		pos->i = i;
		moved = true;
	}
	if (board[(int)pos->i][(int)j] != '1')
	{
		pos->j = j;
		moved = true;
	}
	return (moved);
}

static bool	rotate(t_cub3d *cub3d)
{
	bool	moved;

	moved = false;
	if (cub3d->key == KEY_LEFT)
	{
		cub3d->player.direction += RT_SPEED;
		moved = true;
	}
	else if (cub3d->key == KEY_RIGHT)
	{
		cub3d->player.direction -= RT_SPEED;
		moved = true;
	}
	if (cub3d->player.direction > 2 * M_PI)
		cub3d->player.direction -= 2 * M_PI;
	else if (cub3d->player.direction < 0)
		cub3d->player.direction += 2 * M_PI;
	return (moved);
}

bool	update(t_cub3d *cub3d)
{
	double	direction;
	bool	moved;

	moved = false;
	direction = -1.0f;
	if (cub3d->key == KEY_W)
		direction = cub3d->player.direction + 0 * M_PI / 2;
	else if (cub3d->key == KEY_A)
		direction = cub3d->player.direction + 1 * M_PI / 2;
	else if (cub3d->key == KEY_S)
		direction = cub3d->player.direction + 2 * M_PI / 2;
	else if (cub3d->key == KEY_D)
		direction = cub3d->player.direction + 3 * M_PI / 2;
	if (direction > 0)
	{
		moved = move((const char **)cub3d->map.board, \
			&cub3d->player.pos, direction);
		return (moved);
	}
	moved = rotate(cub3d);
	return (moved);
}
