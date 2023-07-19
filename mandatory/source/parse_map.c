/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:11:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/19 11:46:19 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"

static void	append(t_map *const map, const char *line);
static void	check_valid_map(t_map *const map);
static bool	is_boundary(const int i, const int j, t_map *const map);
static void	set_player(t_map *const map, t_player *const p);

void	parse_map(t_cub3d *const cub3d, const int fd)
{
	char	*line;

	line = ft_get_next_line(fd);
	while (line && ft_strcmp(line, "") == 0)
	{
		free(line);
		line = ft_get_next_line(fd);
	}
	while (line)
	{
		append(&cub3d->map, line);
		line = ft_get_next_line(fd);
		if (line == NULL)
			break ;
		_assert(ft_strcmp(line, "") != 0, "Empty line in map\n");
	}
	check_valid_map(&cub3d->map);
	set_player(&cub3d->map, &cub3d->player);
}

static void	append(t_map *const map, const char *line)
{
	char	**new_board;

	if (map->size == map->capacity)
	{
		map->capacity <<= 1;
		new_board = malloc(sizeof(char *) * map->capacity);
		_assert(new_board != NULL, "append() memory allocation failed\n");
		ft_memcpy(new_board, map->board, sizeof(char *) * map->size);
		free(map->board);
		map->board = new_board;
	}
	map->board[map->size++] = (char *)line;
}

static void	check_valid_map(t_map *const map)
{
	int					i;
	int					j;
	int					player_count;
	int					pos;

	player_count = 0;
	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (map->board[i][j] != '\0')
		{
			pos = _strfind("NSWE01 ", map->board[i][j]);
			_assert(pos < 7, "Map includes not allowed character\n");
			_assert(pos >= 5 || is_boundary(i, j, map) == false,
				"Map boundary includes not wall character\n");
			player_count += (pos <= 3);
			++j;
		}
		++i;
	}
	_assert(player_count == 1, "Player's count is not 1\n");
}

static bool	is_boundary(const int i, const int j, t_map *const map)
{
	_assert(i != 0, "i is zero\n");
	_assert(j != 0, "j is zero\n");
	_assert(i != map->size - 1, "i is map->size - 1\n");
	_assert(map->board[i][j + 1] != '\0', "map->board[i][j + 1] not null ch\n");
	return (
		(ft_strlen(map->board[i - 1]) <= (size_t)j || \
		map->board[i - 1][j] == ' ') || \
		(ft_strlen(map->board[i + 1]) <= (size_t)j || \
		map->board[i + 1][j] == ' ') || \
		map->board[i][j - 1] == ' ' || map->board[i][j + 1] == ' '
	);
}

void	set_player(t_map *const map, t_player *const p)
{
	int			i;
	int			j;
	int			off;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (map->board[i][j] != '\0')
		{
			off = _strfind("SENW", map->board[i][j]);
			if (off == 4)
			{
				++j;
				continue ;
			}
			map->board[i][j] = '0';
			p->pos.i = i;
			p->pos.j = j;
			p->direction = off * M_PI / 2;
			return ;
		}
		++i;
	}
}
