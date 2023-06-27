/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:49:14 by juwkim            #+#    #+#             */
/*   Updated: 2023/06/28 07:41:34 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// C system headers
# include <mlx.h>		// To use mlx fuctions
# include <stdio.h>		// To use in and out fuctions
# include <stdlib.h>	// To allocate memory dynamically
# include <string.h>	// To use string utils functions
# include <unistd.h>	// To use primitive system calls
# include <stdbool.h>	// To use true and false
# include <sys/errno.h>	// To use errno
# include <sys/fcntl.h> // TO use file related system calls

// project headers
# include "libft.h"		// libft utile functions
# include "utils.h"		// util functions

# define PROGRAM			"cub3D"
# define WIN_HEIGHT			5120
# define WIN_WIDTH			2880
# define DIRECTION_COUNT	6

enum e_texture
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	NONE
};

enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	WALL
};

enum e_level
{
	FLOOR,
	CEILING,
	LEVEL
};

typedef struct s_map
{
	char			**board;
	unsigned int	*data_addr[DIRECTION_COUNT];
	int				char_dir;
	int				board_size;
	int				board_capacity;
}	t_map;

typedef struct s_cub3d
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
}	t_cub3d;

#endif // __CUB3D_H__
