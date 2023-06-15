/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:35:15 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/15 22:48:19 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# include "ft_enum.h"
# include <unistd.h>

# define P_NAME "cub3D"
# define WIN_HEIGHT 5120
# define WIN_WIDTH 2880

typedef struct s_info		t_info;
typedef struct s_map		t_map;
typedef struct s_cub3d		t_cub3d;

struct s_info
{
	int				char_dir;
	unsigned int	*pixel_addr[DIR];
};

struct s_map
{
	t_info	info;
	char	**board;
	int		board_size;
	int		board_capacity;
	int		max_length;
};

struct s_cub3d
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
};

#endif
