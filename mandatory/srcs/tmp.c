/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:11:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/06/24 08:21:11 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	skip_empty_line(char *line)
{
	if (ft_strcmp(line, "\n") == 0)
	{
		free(line);
		return (true);
	}
	return (false);
}

int	set_identifier(char *str, const char **identifiers)
{
	int	index;

	index = 0;
	while (identifiers[index])
	{
		if (ft_strcmp(str, identifiers[index]) == 0)
			return (index);
		index++;
	}
	return (DIRECTION_COUNT);
}

bool	is_valid_rgb_data(char **texture)
{
	int	count;
	int	index_char;

	count = 1;
	while (texture[count])
	{
		index_char = 0;
		while (texture[count][index_char])
		{
			if (ft_isdigit(texture[count][index_char]) == false)
				return (false);
			index_char++;
		}
		count++;
	}
	if (count != 4)
		return (false);
	return (true);
}

bool	is_valid_texture(char **texture, int id)
{
	return ((id < FL \
			&& is_extension(texture[1], ".xpm")) \
		|| ((FL <= id && id < DIRECTION_COUNT) \
			&& is_valid_rgb_data(texture)));
}

bool	set_info_image(t_cub3d *cub3d, t_map *map, char **texture, int id)
{
	int		fd;
	void	*img_ptr;

	fd = open(texture[1], O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	img_ptr = ft_mlx_xpm_file_to_image(cub3d->mlx_ptr, texture[1]);
	map->pixel_addr[id] = ft_mlx_get_data_addr(cub3d->mlx_ptr);
	mlx_destroy_image(cub3d->mlx_ptr, img_ptr);
	return (true);
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

bool	set_info_rgb(t_cub3d *cub3d, t_map *map, char **texture, int id)
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
		if (in_range == 0 \
			|| (rgb[index_rgb] < 0 || 255 < rgb[index_rgb]))
			return (false);
		index_rgb++;
	}
	color = (unsigned int)(rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	img_ptr = ft_mlx_new_image(cub3d->mlx_ptr, WIN_HEIGHT, WIN_HEIGHT);
	map->pixel_addr[id] = ft_mlx_get_data_addr(cub3d->mlx_ptr);
	mlx_destroy_image(cub3d->mlx_ptr, img_ptr);
	colored_image(map->pixel_addr[id], color);
	return (true);
}

bool	set_info_texture(t_cub3d *cub3d, t_map *map, char **texture)
{
	const char	*surface_id[7] = {"NO", "SO", "WE", "EA", \
								"F", "C", NULL};
	int			result;
	int			id;

	id = set_identifier(texture[0], surface_id);
	if (is_valid_texture(texture, id) == false)
		id = DIRECTION_COUNT;
	result = false;
	if (NO <= id && id < FL)
		result = set_info_image(cub3d, map, texture, id);
	else if (FL <= id && id < DIRECTION_COUNT)
		result = set_info_rgb(cub3d, map, texture, id);
	ft_free_strings(&texture);
	return (result);
}

bool	check_all_textures(t_map *map)
{
	int	index;

	index = 0;
	while (index < DIRECTION_COUNT)
	{
		if (map->pixel_addr[index] == NULL)
			return (false);
		index++;
	}
	return (true);
}

bool	trim_new_line(char **readline)
{
	char	*trimmed_line;
	size_t	length;

	length = ft_strlen(*readline);
	if (length != 0 && *readline[length - 1] == '\n')
	{
		trimmed_line = malloc(sizeof(char) * (length - 1));
		if (trimmed_line == NULL)
			return (false);
		ft_memmove(trimmed_line, *readline, length - 1);
		trimmed_line[length - 1] = '\0';
		free(*readline);
		*readline = trimmed_line;
	}
	return (true);
}

bool	append_to_board(t_map *map, char *readline)
{
	char	**tmp_board;
	int		line_length;

	if (map->board_size == map->board_capacity)
	{
		tmp_board = malloc(sizeof(char *) * (map->board_size * 2));
		if (tmp_board == NULL)
			return (false);
		ft_memmove(tmp_board, map->board, map->board_size);
		free(map->board);
		map->board = tmp_board;
		map->board_capacity *= 2;
	}
	if (trim_new_line(&readline) == false)
		return (false);
	map->board[map->board_size++] = readline;
	line_length = ft_strlen(readline);
	if (map->max_length < line_length)
		map->max_length = line_length;
	return (true);
}

bool	trim_board_margine(t_map *map)
{
	char	**result;

	if (map->board_size == 0)
		return (false);
	result = malloc(sizeof(char *) * (map->board_size + 1));
	if (result == NULL)
		return (false);
	ft_memmove(result, map->board, map->board_size);
	result[map->board_size] = NULL;
	free(map->board);
	map->board = result;
	return (true);
}

bool	expand_line_length(t_map *map)
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
				return (false);
			ft_memmove(expand_line, map->board[index], length);
			ft_memset(expand_line + length, ' ', map->max_length - length);
			expand_line[map->max_length] = '\0';
		}
		index++;
	}
	return (true);
}

bool	is_in_boundary(int index_y, int index_x, t_map *map)
{
	return (index_y == 0 || index_y == map->board_size - 1 \
			|| index_x == 0 || index_x == map->max_length);
}

// Need to name this function 
// feat: is placed wall, ground, player direction at up, down, left, right side
bool	is_udlr_wgp(t_map *map, int index_y, int index_x)
{
	if ((index_y != 0 \
			&& ft_issep(map->board[index_y - 1][index_x], "01NSWE") == false) \
		|| (index_y != map->board_size - 1 \
			&& ft_issep(map->board[index_y + 1][index_x], "01NSWE") == false) \
		|| (index_x != 0 \
			&& ft_issep(map->board[index_y][index_x - 1], "01NSWE") == false) \
		|| (index_x != map->max_length - 1 \
			&& ft_issep(map->board[index_y][index_x + 1], "01NSWE") == false))
		return (false);
	return (true);
}

bool	is_valid_board(t_map *map)
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
				|| (ft_issep(map->board[index_y][index_x], "NSWE") == true \
					&& ++player_count))
			{
				if (is_in_boundary(index_y, index_x, map) == true)
					return (false);
				if (is_udlr_wgp(map, index_y, index_x) == false)
					return (false);
			}
			index_x++;
		}
		index_y++;
	}
	if (player_count != 1)
		return (false);
	return (true);
}

bool	set_board(t_map *map, int fd)
{
	char	*readline;
	int		result;

	while (1)
	{
		result = get_next_line(&readline, fd);
		if (result == -1)
			return (false);
		else if (readline == NULL)
			break ;
		if (append_to_board(map, readline) == false)
		{
			free(readline);
			return (false);
		}
		free(readline);
	}
	if (trim_board_margine(map) == false)
		return (false);
	expand_line_length(map);
	if (is_valid_board(map) == false)
		return (false);
	return (true);
}