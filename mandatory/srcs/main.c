/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:23:18 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/13 10:51:36 by yeongo           ###   ########.fr       */
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
#include <stdio.h>
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
	int	data;
	int	in_range;

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
		in_range = ft_atoi(texture[count], &data);
		if (!in_range || data < 0 || 255 < data)
			return (FAIL);
		count++;
	}
	if (count != 4)
		return (FAIL);
	return (SUCCESS);
}

int	is_valid_texture(char **texture, int id)
{
	if (id < FL)
	{
		if (!is_valid_file_format(texture[1], ".xpm"))
			return (FAIL);
	}
	else
	{
		if (!is_valid_rgb_data(texture))
			return (FAIL);
	}
	return (SUCCESS);
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

int	set_info_rgb(t_info *info, char **texture, int id)
{
	int	index_rgb;
	int	rgb[3];

	index_rgb = 0;
	while (index_rgb < 3)
	{
		ft_atoi(texture[index_rgb + 1], &rgb[index_rgb]);
		index_rgb++;
	}
	info->rgb[id] = rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	return (SUCCESS);
}

int	set_info_texture(t_cub3d *cub3d, t_info *info, char **texture)
{
	const char	*surface_id[7] = {"NO", "SO", "WE", "EA", \
								"F", "C", NULL};
	int			id;
	int			result;

	id = is_identifier(texture[0], surface_id);
	if (id != DIR)
		if (!is_valid_texture(texture, id))
			id = DIR;
	result = FAIL;
	if (NO <= id && id < FL)
		result = set_info_image(cub3d, info, texture, id);
	else if (FL <= id && id < DIR)
		result = set_info_rgb(info, texture, id - WALL);
	ft_free_strings(&texture);
	if (id == DIR || result == FAIL)
		return (FAIL);
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
		readline = get_next_line(fd);
		if (readline == NULL)
		{
			syscall_err();
			return (FAIL);
		}
		else if (skip_empty_line(&readline))
			continue ;
		texture = ft_split_set(readline, " ,\n");
		if (!set_info_texture(cub3d, info, texture))
			return (FAIL);
		texture_count++;
	}
	return (SUCCESS);
}

int	parse_map(t_cub3d *cub3d, char *map_path)
{
	const int	fd = open_file(map_path);

	if (fd == -1)
		return (FAIL);
	if (!get_texture(cub3d, fd))
		return (FAIL);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_cub3d	cub3d;

	if (!check_valid_argument(ac, av))
		return (1);
	if (!parse_map(&cub3d, av[1]))
		return (1);
	return (0);
}
