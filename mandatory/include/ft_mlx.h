/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:42:59 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/24 08:20:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include "cub3d.h"

void	*ft_mlx_init(void);
void	*ft_mlx_new_window(void *mlx_ptr, int size_x, int size_y);
void	*ft_mlx_new_image(void *mlx_ptr, int width, int height);
void	*ft_mlx_xpm_file_to_image(void *mlx_ptr, char *filename);
char	*ft_mlx_get_data_addr(void *img_ptr);

#endif // __FT_MLX_H__
