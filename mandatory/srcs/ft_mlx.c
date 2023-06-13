/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:49:20 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/13 00:45:09 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_enum.h"
#include "ft_struct.h"
#include "ft_error.h"
#include <mlx.h>
#include <stdlib.h>

void	ft_mlx_init(void **mlx_ptr)
{
	*mlx_ptr = mlx_init();
	if (*mlx_ptr == NULL)
	{
		ft_puterr("Fail to mlx_init");
		exit(1);
	}
}

void	ft_mlx_new_window(void *mlx_ptr, void **win_ptr, int size_x, int size_y)
{
	*win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, P_NAME);
	if (*win_ptr == NULL)
	{
		ft_puterr("Fail to mlx_new_window");
		exit(1);
	}
}

void	ft_mlx_xpm_file_to_image(void *mlx_ptr, void **img_ptr, char *img_path)
{
	int	width;
	int	height;

	*img_ptr = mlx_xpm_file_to_image(mlx_ptr, img_path, &width, &height);
	if (*img_ptr == NULL)
	{
		ft_puterr("Fail to mlx_xpm_file_to_image");
		exit(1);
	}
}

void	ft_mlx_get_data_addr(void *img_ptr, char **pixel_addr)
{
	int	bpp;
	int	size_line;

	*pixel_addr = mlx_get_data_addr(img_ptr, &bpp, &size_line, 0);
	if (*pixel_addr == NULL)
	{
		ft_puterr("Fail to mlx_get_data_addr");
		exit(1);
	}
}

void	ft_mlx_pixel_put(t_cub3d *cub3d)
{
	int	x;
	int	y;

	mlx_pixel_put
		(cub3d->mlx_ptr, cub3d->win_ptr, x, y, cub3d->map.info.rgb[FLOOR]);
	mlx_pixel_put
		(cub3d->mlx_ptr, cub3d->win_ptr, x, y, cub3d->map.info.rgb[CEILING]);
}
