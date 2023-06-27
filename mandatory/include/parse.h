/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:16:19 by juwkim            #+#    #+#             */
/*   Updated: 2023/06/28 07:09:43 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"
# include "ft_mlx.h"

// parse.c
bool	parse(t_cub3d *const cub3d, const int fd);

// parse_texture.c
bool	parse_texture(t_cub3d *const cub3d, const int fd);

// parse_map.c
bool	parse_map(t_map *const map, const int fd);

#endif // __PARSE_H__
