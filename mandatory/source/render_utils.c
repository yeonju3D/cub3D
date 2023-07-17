/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 05:17:04 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 08:04:41 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	set_step(t_vec *vec)
{
	if (vec->ray_dir.x < 0)
	{
		vec->step.x = -1;
		vec->side_dist.x = (vec->pos.x - vec->map.x) * vec->delta_dist.x;
	}
	else
	{
		vec->step.x = 1;
		vec->side_dist.x = (vec->map.x + 1 - vec->pos.x) * vec->delta_dist.x;
	}
	if (vec->ray_dir.y < 0)
	{
		vec->step.y = -1;
		vec->side_dist.y = (vec->pos.y - vec->map.y) * vec->delta_dist.y;
	}
	else
	{
		vec->step.y = 1;
		vec->side_dist.y = (vec->map.y + 1 - vec->pos.y) * vec->delta_dist.y;
	}
}

void	set_vector(t_vec *vec, int x)
{
	vec->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	vec->ray_dir.x = vec->dir.x + vec->plane.x * vec->camera_x;
	vec->ray_dir.y = vec->dir.y + vec->plane.y * vec->camera_x;
	vec->map.x = (int)vec->pos.x;
	vec->map.y = (int)vec->pos.y;
	vec->delta_dist.x = fabs(1 / vec->ray_dir.x);
	vec->delta_dist.y = fabs(1 / vec->ray_dir.y);
	set_step(vec);
}

static void	chk_hit(t_cub3d *cub3d)
{
	t_vec	*vec;
	int		hit;

	hit = 0;
	vec = &(cub3d->vec);
	while (0 == hit)
	{
		if (vec->side_dist.x < vec->side_dist.y)
		{
			vec->side_dist.x += vec->delta_dist.x;
			vec->map.x += vec->step.x;
			vec->side = 0;
		}
		else
		{
			vec->side_dist.y += vec->delta_dist.y;
			vec->map.y += vec->step.y;
			vec->side = 1;
		}
		if ('1' == cub3d->map.board[vec->map.y][vec->map.x])
			hit = 1;
	}
}

void	dda(t_cub3d *cub3d, t_vec *vec, t_draw *draw)
{
	chk_hit(cub3d);
	vec->perp_wall_dist = (vec->map.x - vec->pos.x + (1 - vec->step.x) / 2)
		/ vec->ray_dir.x;
	if (vec->side == 1)
	{
		vec->perp_wall_dist = (vec->map.y - vec->pos.y + (1 - vec->step.y) / 2)
			/ vec->ray_dir.y;
	}
	draw->line_hei = (int)(WIN_HEIGHT / vec->perp_wall_dist);
	draw->draw_start = (WIN_HEIGHT / 2) - (draw->line_hei / 2);
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end = (WIN_HEIGHT / 2) + (draw->line_hei / 2);
	if (draw->draw_end >= WIN_HEIGHT)
		draw->draw_end = WIN_HEIGHT - 1;
	if (vec->side == 0)
		draw->wall_x = vec->pos.y + vec->perp_wall_dist * vec->ray_dir.y;
	else
		draw->wall_x = vec->pos.x + vec->perp_wall_dist * vec->ray_dir.x;
	draw->wall_x -= floor(draw->wall_x);
	draw->tex.x = (int)(draw->wall_x * (double)TEX_WID);
	draw->step = 1.0 * WIN_HEIGHT / draw->line_hei;
	draw->tex_pos = (draw->draw_start - (WIN_HEIGHT / 2 - draw->line_hei / 2))
		*draw->step;
}

void	set_wall_texture(t_cub3d *cub3d)
{
	if (0 == cub3d->vec.side && 1 == cub3d->vec.step.x)
		cub3d->draw.wall_idx = EAST;
	else if (0 == cub3d->vec.side && -1 == cub3d->vec.step.x)
		cub3d->draw.wall_idx = WEST;
	else if (1 == cub3d->vec.side && 1 == cub3d->vec.step.y)
		cub3d->draw.wall_idx = SOUTH;
	else
		cub3d->draw.wall_idx = NORTH;
}
