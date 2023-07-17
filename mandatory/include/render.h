/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:43:07 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 05:25:01 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

void	set_vector(t_vec *vec, int x);
void	dda(t_cub3d *cub3d, t_vec *vec, t_draw *draw);
void	set_wall_texture(t_cub3d *cub3d);

void	render(t_cub3d *cub3d);

#endif // __RENDER_H__
