/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:11:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/06/28 07:13:07 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	parse_map(t_map *const map, const int fd)
{
	char	*line;

	while (true)
	{
		line = ft_get_next_line(fd);
		if (line == NULL)
			break ;
		if (append_to_board(map, line) == false)
		{
			free(line);
			return (false);
		}
		free(line);
	}
	if (trim_board_margine(map) == false)
		return (false);
	expand_line_length(map);
	if (is_valid_board(map) == false)
		return (false);
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
