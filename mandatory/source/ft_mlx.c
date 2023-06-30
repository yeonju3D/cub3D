/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:49:20 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/30 10:44:14 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	*ft_mlx_init(void)
{
	const void	*mlx_ptr = mlx_init();

	if (mlx_ptr == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Fail to mlx_init()");
		exit(EXIT_FAILURE);
	}
	return ((void *)mlx_ptr);
}

void	*ft_mlx_new_window(void *mlx_ptr, const int size_x, const int size_y)
{
	const void	*win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, PROGRAM);

	if (win_ptr == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Fail to mlx_new_window()");
		exit(EXIT_FAILURE);
	}
	return ((void *)win_ptr);
}

void	*ft_mlx_new_image(void *mlx_ptr, const int width, const int height)
{
	const void	*img_ptr = mlx_new_image(mlx_ptr, width, height);

	if (img_ptr == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Fail to mlx_new_image()");
		exit(EXIT_FAILURE);
	}
	return ((void *)img_ptr);
}

void	*ft_mlx_xpm_file_to_image(void *mlx_ptr, const char *filename)
{
	int			width;
	int			height;
	const void	*img_ptr = \
		mlx_xpm_file_to_image(mlx_ptr, (char *)filename, &width, &height);

	if (img_ptr == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Fail to mlx_xpm_file_to_image()");
		exit(EXIT_FAILURE);
	}
	return ((void *)img_ptr);
}

char	*ft_mlx_get_data_addr(void *img_ptr)
{
	int			bits_per_pixel;
	int			size_line;
	const char	*data_addr = \
		mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, NULL);

	if (data_addr == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Fail to mlx_get_data_addr()");
		exit(EXIT_FAILURE);
	}
	return ((char *)data_addr);
}
