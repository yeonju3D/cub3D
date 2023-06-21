/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enum.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:36:25 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/21 20:07:08 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENUM_H
# define FT_ENUM_H

enum e_texture
{
	NO,
	SO,
	WE,
	EA,
	FL,
	CE,
	DIR
};

enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	WALL,
	NONE
};

enum e_level
{
	FLOOR,
	CEILING,
	LEVEL
};

enum e_return
{
	FAIL,
	SUCCESS
};

#endif
