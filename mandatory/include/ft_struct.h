/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:35:15 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/21 20:06:34 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# include "ft_enum.h"
# include <unistd.h>

# define P_NAME "cub3D"
# define WIN_HEIGHT 5120
# define WIN_WIDTH 2880

typedef struct s_map	t_map;
typedef struct s_cub3d	t_cub3d;

struct s_map
{
	char			**board;
	unsigned int	*pixel_addr[DIR];
	int				char_dir;
	int				board_size;
	int				board_capacity;
	int				max_length;
};

struct s_cub3d
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
};

#endif // FT_STRUCT_H__FT_STRUCT_H__
