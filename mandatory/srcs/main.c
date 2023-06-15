/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:23:18 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/15 22:57:16 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_enum.h"
#include "ft_struct.h"
#include "ft_mlx.h"
#include "ft_error.h"
#include "ft_ctype.h"
#include "ft_string.h"
#include "ft_split.h"
#include "get_next_line.h"
#include "ft_memory.h"
#include "libft.h"
#include <mlx.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>

int	is_valid_file_format(char *map_path, char *file_exp)
{
	size_t	path_length;
	size_t	exp_length;

	path_length = ft_strlen(map_path);
	exp_length = ft_strlen(file_exp);
	return (ft_strnstr
		(map_path + path_length - exp_length, file_exp, exp_length + 1) \
		&& path_length > exp_length);
}

int	check_valid_argument(int ac, char **av)
{
	if (ac != 2)
	{
		ft_puterr("");
		return (FAIL);
	}
	if (!is_valid_file_format(av[1], ".cub"))
	{
		ft_puterr("Invalid map path format");
		return (FAIL);
	}
	return (SUCCESS);
}

void	init_map_data(t_map *map)
{
	int	index;

	map->info.char_dir = NONE;
	index = 0;
	while (index < DIR)
	{
		map->info.pixel_addr[index] = NULL;
		index++;
	}
	map->board = NULL;
}

int	open_file(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		syscall_err();
	return (fd);
}

int	skip_empty_line(char **readline)
{
	if (ft_strncmp(*readline, "\n", 2) == 0)
	{
		free(*readline);
		return (TRUE);
	}
	return (FALSE);
}

int	is_identifier(char *str, const char **identifiers)
{
	int	index;

	index = 0;
	while (identifiers[index])
	{
		if (ft_strncmp
			(str, identifiers[index], ft_strlen(identifiers[index]) + 1) == 0)
			return (index);
		index++;
	}
	return (DIR);
}

int	is_valid_rgb_data(char **texture)
{
	int	count;
	int	index_char;

	count = 1;
	while (texture[count])
	{
		index_char = 0;
		while (texture[count][index_char])
		{
			if (!ft_isdigit(texture[count][index_char]))
				return (FAIL);
			index_char++;
		}
		count++;
	}
	if (count != 4)
		return (FAIL);
	return (SUCCESS);
}

int	is_valid_texture(char **texture, int id)
{
	return ((id < FL \
			&& is_valid_file_format(texture[1], ".xpm")) \
		|| ((FL <= id && id < DIR) \
			&& is_valid_rgb_data(texture)));
}

int	set_info_image(t_cub3d *cub3d, t_info *info, char **texture, int id)
{
	int		fd;
	void	*img_ptr;

	fd = open(texture[1], O_RDONLY);
	if (fd == -1)
		return (FAIL);
	close(fd);
	ft_mlx_xpm_file_to_image(cub3d->mlx_ptr, &img_ptr, texture[1]);
	ft_mlx_get_data_addr(cub3d->mlx_ptr, &info->pixel_addr[id]);
	mlx_destroy_image(cub3d->mlx_ptr, img_ptr);
	return (SUCCESS);
}

void	colored_image(unsigned int *pixel_addr, unsigned int color)
{
	unsigned int	index;
	unsigned int	max_pixel;

	index = 0;
	max_pixel = WIN_HEIGHT * WIN_WIDTH;
	while (index < max_pixel)
	{
		*(pixel_addr + index) = color;
		index++;
	}
}

int	set_info_rgb(t_cub3d *cub3d, t_info *info, char **texture, int id)
{
	int				index_rgb;
	int				rgb[3];
	int				in_range;
	unsigned int	color;
	void			*img_ptr;

	index_rgb = 0;
	while (index_rgb < 3)
	{
		in_range = ft_atoi(texture[index_rgb + 1], &rgb[index_rgb]);
		if (!in_range \
			|| (rgb[index_rgb] < 0 || 255 < rgb[index_rgb]))
			return (FAIL);
		index_rgb++;
	}
	color = (unsigned int)(rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	ft_mlx_new_image(cub3d->mlx_ptr, &img_ptr, WIN_HEIGHT, WIN_HEIGHT);
	ft_mlx_get_data_addr(cub3d->mlx_ptr, &info->pixel_addr[id]);
	mlx_destroy_image(cub3d->mlx_ptr, img_ptr);
	colored_image(info->pixel_addr[id], color);
	return (SUCCESS);
}

int	set_info_texture(t_cub3d *cub3d, t_info *info, char **texture)
{
	const char	*surface_id[7] = {"NO", "SO", "WE", "EA", \
								"F", "C", NULL};
	int			result;
	int			id;

	id = is_identifier(texture[0], surface_id);
	if (!is_valid_texture(texture, id))
		id = DIR;
	result = FAIL;
	if (NO <= id && id < FL)
		result = set_info_image(cub3d, info, texture, id);
	else if (FL <= id && id < DIR)
		result = set_info_rgb(cub3d, info, texture, id);
	ft_free_strings(&texture);
	return (result);
}

int	check_all_textures(t_info *info)
{
	int	index;

	index = 0;
	while (index < DIR)
	{
		if (!info->pixel_addr[index])
			return (FAIL);
		index++;
	}
	return (SUCCESS);
}

int	get_texture(t_cub3d *cub3d, int fd)
{
	char			*readline;
	char			**texture;
	int				texture_count;
	t_info * const	info = &cub3d->map.info;

	texture_count = 0;
	while (texture_count < DIR)
	{
		if (get_next_line(&readline, fd) == FAIL)
		{
			syscall_err();
			return (FAIL);
		}
		else if (skip_empty_line(&readline))
			continue ;
		if (readline == NULL)
			return (FAIL);
		texture = ft_split_set(readline, " ,\n");
		if (!set_info_texture(cub3d, info, texture))
			return (FAIL);
		texture_count++;
	}
	return (check_all_textures(info));
}

int	trim_new_line(char **readline)
{
	char	*trimmed_line;
	size_t	length;

	length = ft_strlen(*readline);
	if (length != 0 && *readline[length - 1] == '\n')
	{
		trimmed_line = malloc(sizeof(char) * (length - 1));
		if (trimmed_line == NULL)
			return (FAIL);
		ft_memmove(trimmed_line, *readline, length - 1);
		trimmed_line[length - 1] = '\0';
		free(*readline);
		*readline = trimmed_line;
	}
	return (SUCCESS);
}

int	append_to_board(t_map *map, char *readline)
{
	char	**tmp_board;
	int		line_length;

	if (map->board_size == map->board_capacity)
	{
		tmp_board = malloc(sizeof(char *) * (map->board_size * 2));
		if (tmp_board == NULL)
			return (FAIL);
		ft_memmove(tmp_board, map->board, map->board_size);
		free(map->board);
		map->board = tmp_board;
		map->board_capacity *= 2;
	}
	if (!trim_new_line(&readline))
		return (FAIL);
	map->board[map->board_size++] = readline;
	line_length = ft_strlen(readline);
	if (map->max_length < line_length)
		map->max_length = line_length;
	return (SUCCESS);
}

int	trim_board_margine(t_map *map)
{
	char	**result;

	if (map->board_size == 0)
		return (FAIL);
	result = malloc(sizeof(char *) * (map->board_size + 1));
	if (result == NULL)
		return (FAIL);
	ft_memmove(result, map->board, map->board_size);
	result[map->board_size] = NULL;
	free(map->board);
	map->board = result;
	return (SUCCESS);
}

int	expand_line_length(t_map *map)
{
	int		index;
	int		length;
	char	*expand_line;

	index = 0;
	while (map->board[index])
	{
		length = ft_strlen(map->board[index]);
		if (length != map->max_length)
		{
			expand_line = malloc(sizeof(char) * (map->max_length + 1));
			if (expand_line == NULL)
				return (0);
			ft_memmove(expand_line, map->board[index], length);
			ft_memset(expand_line + length, ' ', map->max_length - length);
			expand_line[map->max_length] = '\0';
		}
		index++;
	}
	return (1);
}

int	in_boundary(int index_y, int index_x, t_map *map)
{
	if (index_y == 0 || index_y == map->board_size - 1 \
	|| index_x == 0 || index_x == map->max_length)
		return (1);
	return (0);
}

int	is_valid_board(t_map *map)
{
	int	index_y;
	int	index_x;
	int	player_count;

	player_count = 0;
	index_y = 0;
	while (map->board[index_y])
	{
		index_x = 0;
		while (map->board[index_y][index_x])
		{
			if (map->board[index_y][index_x] == '0' \
				|| (ft_issep(map->board[index_y][index_x], "NSWE") \
					&& ++player_count))
			{
				if (in_boundary(index_y, index_x, map))
					return (FAIL);
				// 상하좌우 벽땅플 아니면 페일
			}
			index_x++;
		}
		index_y++;
	}
	return (SUCCESS);
}

int	get_board(t_map *map, int fd)
{
	char	*readline;
	int		result;

	while (1)
	{
		result = get_next_line(&readline, fd);
		if (result == -1)
			return (FAIL);
		else if (readline == NULL)
			break ;
		if (append_to_board(map, readline) == FAIL)
		{
			free(readline);
			return (FAIL);
		}
		free(readline);
	}
	if (trim_board_margine(map) == FAIL)
		return (FAIL);
	expand_line_length(map);
	if (!is_valid_board(map))
		return (FAIL);
	return (SUCCESS);
}

int	parse_map(t_cub3d *cub3d, char *map_path)
{
	const int	fd = open_file(map_path);

	if (fd == -1)
		return (FAIL);
	if (!get_texture(cub3d, fd))
		return (FAIL);
	if (!get_board(&cub3d->map, fd))
		return (FAIL);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_cub3d	cub3d;

	if (!check_valid_argument(ac, av))
		return (1);
	init_map_data(&cub3d.map);
	if (!parse_map(&cub3d, av[1]))
		return (1);
	return (0);
}
