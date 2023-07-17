/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 06:16:22 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 05:22:27 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"

static void			set_texture(t_cub3d *const cub3d, const char *line);
static t_direction	get_texture_identifier(const char *line);
static void			set_texture_image(t_cub3d *const cub3d, \
							const char *image_path, const t_direction id);
static void			set_texture_color(t_cub3d *const cub3d, \
							const char **rgb, const t_direction id);

void	parse_texture(t_cub3d *const cub3d, const int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (count < DIRECTION_COUNT)
	{
		line = ft_get_next_line(fd);
		if (strcmp(line, "") == 0)
		{
			free(line);
			continue ;
		}
		set_texture(cub3d, line);
		free(line);
		++count;
	}
}

static void	set_texture(t_cub3d *const cub3d, const char *line)
{
	const t_direction	id = get_texture_identifier(line);
	char				**rgb;
	int					index;

	_assert(id != NONE, "Texture identifier is NONE\n");
	if (id == NORTH || id == SOUTH || id == WEST || id == EAST)
		set_texture_image(cub3d, line + 3, id);
	else
	{
		_assert(cub3d->map.color[id] == 0, "Duplicated color\n");
		rgb = ft_split(line + 2, ',');
		_assert(rgb != NULL, "set_texture() memory allocation failed\n");
		set_texture_color(cub3d, (const char **)rgb, id);
		index = 0;
		while (rgb[index])
			free(rgb[index++]);
		free(rgb);
	}
}

static t_direction	get_texture_identifier(const char *line)
{
	if (ft_strncmp(line, "NO ", ft_strlen("NO ")) == 0)
		return (NORTH);
	if (ft_strncmp(line, "SO ", ft_strlen("SO ")) == 0)
		return (SOUTH);
	if (ft_strncmp(line, "WE ", ft_strlen("WE ")) == 0)
		return (WEST);
	if (ft_strncmp(line, "EA ", ft_strlen("EA ")) == 0)
		return (EAST);
	if (ft_strncmp(line, "F ", ft_strlen("F ")) == 0)
		return (FLOOR);
	if (ft_strncmp(line, "C ", ft_strlen("C ")) == 0)
		return (CEILING);
	return (NONE);
}

static void	set_texture_image(t_cub3d *const cub3d, \
	const char *image_path, const t_direction id)
{
	t_img *const	simg = &cub3d->map.img[id];

	_assert(is_extension(image_path, ".xpm"), "image is not xpm file\n");
	_assert(simg->pixel == NULL, "Duplicated image\n");
	simg->pixel = mlx_xpm_file_to_image(cub3d->mlx, (char *)image_path, \
		&simg->width, &simg->height);
	_assert(simg->pixel != NULL, "mlx_xpm_file_to_image() failed\n");
	simg->addr = mlx_get_data_addr(simg->pixel, &simg->bpp, &simg->len,
			&simg->endian);
	_assert(simg->addr != NULL, "mlx_get_data_addr() failed\n");
}

static void	set_texture_color(t_cub3d *const cub3d, \
	const char **rgb, const enum e_direction id)
{
	int				index;
	int				num;
	unsigned int	color;

	index = 0;
	color = 0;
	while (index < 3 && rgb[index])
	{
		num = _atoi(rgb[index]);
		_assert(0 <= num && num <= 255, "number is not in range 0 ~ 255\n");
		color = (color << 8) | num;
		++index;
	}
	_assert(index == 3, "color channel is less than 3\n");
	_assert(rgb[3] == NULL, "color channel is larger than 3\n");
	cub3d->map.color[id] = color;
}
