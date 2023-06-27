/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:15:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/06/28 04:41:10 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	parse_map(t_cub3d *const cub3d, const int fd)
{
	if (get_texture(cub3d, fd) == false)
		return (false);
	if (set_board(&cub3d->map, fd) == false)
		return (false);
	return (true);
}

bool	get_texture(t_cub3d *const cub3d, const int fd)
{
	char			*readline;
	char			**texture;
	int				texture_count;
	t_map *const	map = &cub3d->map;

	texture_count = 0;
	while (texture_count < DIRECTION_COUNT)
	{
		if (ft_get_next_line(fd) == false)
		{
			syscall_err();
			return (false);
		}
		else if (skip_empty_line(&readline) == true)
			continue ;
		if (readline == NULL)
			return (false);
		texture = ft_split_set(readline, " ,\n");
		if (set_info_texture(cub3d, map, texture) == false)
			return (false);
		++texture_count;
	}
	return (check_all_textures(map));
}
