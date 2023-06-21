/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:49:20 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/16 23:03:12 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_enum.h"
#include "ft_struct.h"
#include "ft_error.h"
#include <mlx.h>
#include <stdlib.h>

void	*ft_mlx_init(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		ft_puterr("Fail to mlx_init");
		exit(EXIT_FAILURE);
	}
	return (mlx_ptr);
}

void	*ft_mlx_new_window(void *mlx_ptr, int size_x, int size_y)
{
	void	*win_ptr;

	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, P_NAME);
	if (win_ptr == NULL)
	{
		ft_puterr("Fail to mlx_new_window");
		exit(EXIT_FAILURE);
	}
	return (win_ptr);
}

void	*ft_mlx_new_image(void *mlx_ptr, int width, int height)
{
	void	*img_ptr;

	img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (img_ptr == NULL)
	{
		ft_puterr("Fail to mlx_new_image");
		exit(EXIT_FAILURE);
	}
	return (img_ptr);
}

void	*ft_mlx_xpm_file_to_image(void *mlx_ptr, char *img_path)
{
	int		width;
	int		height;
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(mlx_ptr, img_path, &width, &height);
	if (img_ptr == NULL)
	{
		ft_puterr("Fail to mlx_xpm_file_to_image");
		exit(EXIT_FAILURE);
	}
	return (img_ptr);
}

void	*ft_mlx_get_data_addr(void *img_ptr)
{
	int				bpp;
	int				size_line;
	unsigned int	*pixel_addr;

	pixel_addr = (unsigned int *)mlx_get_data_addr
		(img_ptr, &bpp, &size_line, 0);
	if (pixel_addr == NULL)
	{
		ft_puterr("Fail to mlx_get_data_addr");
		exit(EXIT_FAILURE);
	}
	return (pixel_addr);
}
