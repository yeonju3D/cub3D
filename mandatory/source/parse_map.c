/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:11:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 09:29:35 by juwkim           ###   ########.fr       */
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
	while (line && strcmp(line, "") == 0)
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
		_assert(strcmp(line, "") != 0, "Empty line in map\n");
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
	static const char	*allowed = "NSWE01 ";
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
			pos = ft_strchr(allowed, map->board[i][j]) - allowed;
			_assert(pos >= 0, "Map inclueds not allowed character\n");
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
	return (
		i == 0 || i == map->size - 1 || \
	j == 0 || map->board[i][j + 1] == '\0' || \
	((int)ft_strlen(map->board[i - 1]) <= j || map->board[i - 1][j] == ' ') || \
	((int)ft_strlen(map->board[i + 1]) <= j || map->board[i + 1][j] == ' ') || \
	map->board[i][j - 1] == ' ' || map->board[i][j + 1] == ' '
	);
}

void	set_player(t_map *const map, t_player *const p)
{
	static const char	*allowed = "SENW";
	int					i;
	int					j;
	int					off;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (map->board[i][j] != '\0')
		{
			off = ft_strchr(allowed, map->board[i][j]) - allowed;
			if (off < 0)
			{
				++j;
				continue ;
			}
			_assert(off <= 3, "ft_strchr() failed\n");
			p->pos.x = i;
			p->pos.y = j;
			p->direction = off * M_PI / 2;
			return ;
		}
		++i;
	}
}
