/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:35:15 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/07 19:17:23 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

typedef struct s_map	t_map;
typedef struct s_info	t_info;

struct s_tmp
{
	char	*identifier;
	char	*img_path;
	void	*img_ptr;
};

struct s_info
{
	int		direction;
	char	*pixel_addr[4];
};

struct s_map
{
	t_info	*info;
	char	**board;
};

enum e_direction
{
	NO,
	SO,
	WE,
	EA
};

enum e_bool
{
	FALSE,
	TRUE
};

enum e_result
{
	FAIL,
	SUCCESS
};

#endif