/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:35:15 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/09 18:22:02 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# include "ft_enum.h"

# define P_NAME "cub3D"

typedef struct s_texture	t_texture;
typedef struct s_info		t_info;
typedef struct s_map		t_map;
typedef struct s_cub3d		t_cub3d;

struct s_texture
{
	char	*identifier;
	char	*img_path;
	void	*img_ptr;
};

struct s_info
{
	int		char_dir;
	char	*pixel_addr[DIRECTION];
};

struct s_map
{
	t_info	*info;
	char	**board;
};

struct s_cub3d
{
	void	*mlx_ptr;
	void	*win_ptr;
};

#endif
