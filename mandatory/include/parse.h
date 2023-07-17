/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:16:19 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 06:33:41 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"

// parse_texture.c
void	parse_texture(t_cub3d *const cub3d, const int fd);

// parse_map.c
void	parse_map(t_cub3d *const cub3d, const int fd);

#endif // __PARSE_H__
