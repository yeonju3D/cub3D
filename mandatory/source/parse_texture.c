/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 06:16:22 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 20:04:05 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"

static void			set_texture(t_cub3d *const cub3d, const char *line);
static t_direction	get_texture_identifier(const char *line);
static void			set_texture_image(void *mlx_ptr, t_img *const img, \
							const char *image_path);
static void			set_texture_color(t_color *const color_ptr, char **rgb);

void	parse_texture(t_cub3d *const cub3d, const int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (count < IMAGE_COUNT + COLOR_COUNT)
	{
		line = ft_get_next_line(fd);
		_assert(line != NULL, "Not enough texture parsed\n");
		if (ft_strcmp(line, "") == 0)
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
		set_texture_image(cub3d->mlx, &cub3d->img[id], line + 3);
	else
	{
		_assert(cub3d->color[id] == 0, "Duplicated color\n");
		rgb = ft_split(line + 2, ',');
		_assert(rgb != NULL, "set_texture() memory allocation failed\n");
		set_texture_color(&cub3d->color[id], rgb);
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

static void	set_texture_image(void *mlx_ptr, t_img *const img, \
								const char *image_path)
{
	_assert(is_extension(image_path, ".xpm"), "image is not xpm file\n");
	_assert(img->pixels == NULL, "Duplicated image\n");
	img->pixels = mlx_xpm_file_to_image(mlx_ptr, (char *)image_path, \
		&img->width, &img->height);
	_assert(img->pixels != NULL, "mlx_xpm_file_to_image() failed\n");
	img->addr = mlx_get_data_addr(img->pixels, &img->bpp, &img->len,
			&img->endian);
	_assert(img->addr != NULL, "mlx_get_data_addr() failed\n");
}

static void	set_texture_color(t_color *const color_ptr, char **rgb)
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
	*color_ptr = color;
}
