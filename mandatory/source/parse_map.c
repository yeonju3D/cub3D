/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:11:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/06/30 20:45:15 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>

static bool	append_to_board(t_map *const map, const char *line);
static bool	is_valid_board(t_map *const map);
static bool	is_boundary(const int i, const int j, t_map *const map);

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
	}
	map->length = malloc(sizeof(int) * map->board_size);
	return (is_valid_board(map) == false);
}

static bool	append_to_board(t_map *const map, const char *line)
{
	char	**new_board;

	if (map->board_size == map->board_capacity)
	{
		map->board_capacity <<= 1;
		new_board = malloc(sizeof(char *) * map->board_capacity);
		if (new_board == NULL)
			return (false);
		ft_memcpy(new_board, map->board, sizeof(char *) * map->board_size);
		free(map->board);
		map->board = new_board;
	}
	map->board[map->board_size++] = (char *)line;
	return (true);
}

static bool	is_valid_board(t_map *const map)
{
	static const char	*allowed = "NSWE01";
	int					i;
	int					j;
	int					player_count;
	int					pos;

	player_count = 0;
	i = 0;
	while (i < map->board_size)
	{
		j = 0;
		while (map->board[i][j] != '\0')
		{
			pos = ft_strchr(allowed, map->board[i][j]) - allowed;
			if (pos < 0)
				return (false);
			if (pos != 5 && is_boundary(i, j, map) == false)
				return (false);
			player_count += (pos <= 3);
			++j;
		}
		++i;
	}
	return (player_count == 1);
}

static bool	is_boundary(const int i, const int j, t_map *const map)
{
	return (i != 0 && \
			i != map->board_size - 1 && \
			j != 0 && \
			map->board[i][j + 1] != '\0' && \
			map->board[i - 1][j] != ' ' && \
			map->board[i + 1][j] != ' ' && \
			map->board[i][j - 1] != ' ' && \
			map->board[i][j + 1] != ' ');
}
