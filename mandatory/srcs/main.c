/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:23:18 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/09 17:49:08 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include "error.h"
#include <get_next_line.h>
#include <ft_string.h>
#include <ft_split.h>
#include <ft_memory.h>
#include <stdio.h>
#include <sys/fcntl.h>

int	valid_map_format(char *map_path)
{
	size_t	path_length;

	path_length = ft_strlen(map_path);
	return (ft_strnstr(map_path + path_length - 4, ".ber", 5) \
			&& path_length >= 5);
}

int	check_valid_argument(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (!valid_map_format(av[1]))
		return (0);
	return (1);
}

int	open_file(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		syscall_err();
		// ft_puterr("");
	}
	return (fd);
}

int	skip_empty_line(char **readline)
{
	if (ft_strncmp(*readline, "\n", 2) == 0)
	{
		free(*readline);
		return (1);
	}
	return (0);
}

int	is_identifier(char *str, const char **identifiers)
{
	int	index;

	index = 0;
	while (identifiers[index])
	{
		if (ft_strncmp(str, identifiers[index], ft_strlen(identifiers[index]) + 1))
			return (1);
		index++;
	}
	return (0);
}

void	set_wall_info(t_info *info, char **texture)
{
	;
}

void	set_level_info(t_info *info, char **texture);

int	set_texture_info(t_info *info, char **texture)
{
	const char	*wall_id[5] = {"NO", "SO", "EA", "WE", NULL};
	const char	*level_id[3] = {"F", "C", NULL};

	if (is_identifier(texture[0], wall_id))
	{
		set_wall_info(info, texture);
		ft_free_strings(&texture);
		return (1);
	}
	else if (is_identifier(texture[0], level_id))
	{
		set_level_info(info, texture);
		ft_free_strings(&texture);
		return (1);
	}
	ft_free_strings(&texture);
	return (0);
}

int	get_texture(t_info *info, int fd)
{
	char	*readline;
	char	**texture;
	int		texture_count;

	texture_count = 0;
	while (1)
	{
		readline = get_next_line(fd);
		if (readline == NULL)
		{
			printf("hi\n");
			// syscall_err();
			return (0);
		}
		else if (skip_empty_line(&readline))
			continue ;
		texture = ft_split(readline, ' ');
		if (!set_texture_info(info, texture))
			return (0);
		texture_count++;
		if (texture_count == 6)
			break ;
	}
	return (1);
}

int	parse_map(t_map *map, char *map_path)
{
	int	fd = open_file(map_path);

	if (fd == -1)
		return (0);
	if (!get_texture(map->info, fd))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (!check_valid_argument(ac, av))
		return (1);
	if (!parse_map(&map, av[1]))
		return (1);
	return (0);
}
