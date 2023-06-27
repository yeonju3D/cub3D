/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:15:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/06/28 06:17:07 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	parse(t_cub3d *const cub3d, const int fd)
{
	return (parse_texture(cub3d, fd) && parse_map(&cub3d->map, fd));
}
