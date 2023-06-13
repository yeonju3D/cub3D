/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:42:59 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/12 13:26:06 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

void	ft_mlx_init(void **mlx_ptr);
void	ft_mlx_new_window(void *mlx_ptr, void **win_ptr, int x, int y);
void	ft_mlx_xpm_file_to_image(void *mlx_ptr, void **img_ptr, char *img_path);
void	ft_mlx_get_data_addr(void *img_ptr, char **pixel_addr);

#endif
