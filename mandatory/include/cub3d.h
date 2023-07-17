/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:49:14 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 09:59:03 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// C system headers
# include <math.h>		// To use math related functions
# include <stdio.h>		// To use in and out fuctions
# include <stdlib.h>	// To allocate memory dynamically
# include <string.h>	// To use string utils functions
# include <unistd.h>	// To use primitive system calls
# include <stdbool.h>	// To use true and false
# include <sys/errno.h>	// To use errno
# include <sys/fcntl.h> // TO use file related system calls

// project headers
# include "mlx.h"		// mlx fuctions
# include "libft.h"		// libft utile functions

# define PROGRAM			"cub3D"
# define WIN_HEIGHT			1080
# define WIN_WIDTH			1920
# define DIRECTION_COUNT	6

# define MV_SPEED			0.05
# define RT_SPEED			0.03

# define TEX_WID			64
# define TEX_HEI			64


# ifndef M_PI
#  define M_PI 3.14159265358979323846	/* pi */
# endif // __M_PI__

# define AOF	0.78539816339			// M_PI / 4

typedef enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTORY = 17
}	t_event;

typedef enum e_mask
{
	KEY_PRESS_MASK = (1L << 0),
	KEY_RELEASE_MASK = (1L << 1),
	BUTTON_PRESS_MASK = (1L << 2),
	BUTTON_RELEASE_MASK = (1L << 3),
}	t_mask;

# ifdef __linux__

typedef enum e_key
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_ESC = 65307,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_RELESED = 255
}	t_key;

# else

typedef enum e_key
{
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_RELESED = 255
}	t_key;
# endif // __linux__

typedef enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING,
	NONE
}	t_direction;

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_img
{
	void	*pixel;
	int		width;
	int		height;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_map
{
	char			**board;
	int				size;
	int				capacity;
	t_img			img[4];
	unsigned int	color[6];
}	t_map;

typedef struct s_player
{
	t_pos	pos;
	double	direction;
}	t_player;

typedef struct s_vec
{
	t_pos	pos;
	t_pos	dir;
	t_pos	plane;
	t_pos	map;
	t_pos	step;
	int		side;
	double	camera_x;
	t_pos	ray_dir;
	t_pos	side_dist;
	t_pos	delta_dist;
	double	perp_wall_dist;
}	t_vec;

typedef struct s_draw
{
	int		line_hei;
	int		draw_start;
	int		draw_end;
	int		wall_idx;
	double	wall_x;
	double	tex_pos;
	double	step;
	int		color;
	t_pos	tex;
}	t_draw;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	t_key		key;
	t_img		img;
	t_map		map;
	t_player	player;
	t_draw		draw;
}	t_cub3d;

#endif // __CUB3D_H__
