/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 06:16:22 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/09 17:48:00 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool				set_texture(t_cub3d *const cub3d, const char *line);
static enum e_texture	get_texture_identifier(const char *line);
static bool				set_texture_image(t_cub3d *const cub3d, \
							const char *image_path, const enum e_texture id);
static bool				set_texture_color(t_cub3d *const cub3d, \
							const char **rgb, const enum e_texture id);

bool	parse_texture(t_cub3d *const cub3d, const int fd)
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
		if (set_texture(cub3d, line) == false)
			return (false);
		free(line);
		++count;
	}
	return (true);
}

static bool	set_texture(t_cub3d *const cub3d, const char *line)
{
	const enum e_texture	id = get_texture_identifier(line);
	char					**rgb;
	int						result;
	int						index;

	if (id == NONE)
		return (false);
	else if (id == NO || id == SO || id == WE || id == EA)
		result = set_texture_image(cub3d, line + 3, id);
	else
	{
		rgb = ft_split(line + 2, ',');
		if (rgb == NULL)
			return (false);
		result = set_texture_color(cub3d, (const char **)rgb, id);
		index = 0;
		while (rgb[index])
			free(rgb[index++]);
		free(rgb);
	}
	return (result);
}

static enum e_texture	get_texture_identifier(const char *line)
{
	if (ft_strncmp(line, "NO ", ft_strlen("NO ")) == 0)
		return (NO);
	if (ft_strncmp(line, "SO ", ft_strlen("SO ")) == 0)
		return (SO);
	if (ft_strncmp(line, "WE ", ft_strlen("WE ")) == 0)
		return (WE);
	if (ft_strncmp(line, "EA ", ft_strlen("EA ")) == 0)
		return (EA);
	if (ft_strncmp(line, "F ", ft_strlen("F ")) == 0)
		return (F);
	if (ft_strncmp(line, "C ", ft_strlen("C ")) == 0)
		return (C);
	return (NONE);
}

static bool	set_texture_image(t_cub3d *const cub3d, \
	const char *image_path, const enum e_texture id)
{
	void	*img_ptr;

	if (is_extension(image_path, ".xpm") == false)
		return (false);
	img_ptr = ft_mlx_xpm_file_to_image(cub3d->mlx_ptr, image_path);
	cub3d->map.data_addr[id] = (unsigned int *)ft_mlx_get_data_addr(img_ptr);
	mlx_destroy_image(cub3d->mlx_ptr, img_ptr);
	return (true);
}

static bool	set_texture_color(t_cub3d *const cub3d, \
	const char **rgb, const enum e_texture id)
{
	int				index;
	int				num;
	unsigned int	color;
	void			*img_ptr;

	index = 0;
	color = 0;
	while (index < 3 && rgb[index])
	{
		num = ft_atoi(rgb[index]);
		if (num < 0 || num > 255)
			return (false);
		color = (color << 8) | num;
		++index;
	}
	if (rgb[3] != NULL)
		return (false);
	img_ptr = ft_mlx_new_image(cub3d->mlx_ptr, WIN_HEIGHT, WIN_HEIGHT);
	cub3d->map.data_addr[id] = (unsigned int *)ft_mlx_get_data_addr(img_ptr);
	mlx_destroy_image(cub3d->mlx_ptr, img_ptr);
	index = 0;
	while (index < WIN_HEIGHT * WIN_WIDTH)
		cub3d->map.data_addr[id][index++] = color;
	return (true);
}
