/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:42:59 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/16 23:03:49 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

void	*ft_mlx_init(void);
void	*ft_mlx_new_window(void *mlx_ptr, int x, int y);
void	*ft_mlx_new_image(void *mlx_ptr, int width, int height);
void	*ft_mlx_xpm_file_to_image(void *mlx_ptr, char *img_path);
void	*ft_mlx_get_data_addr(void *img_ptr);

#endif
