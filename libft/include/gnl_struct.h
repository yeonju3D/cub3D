/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_struct.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:01:51 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/12 11:03:06 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_STRUCT_H
# define GNL_STRUCT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>

typedef struct s_gnl_buffer	t_gnl_buffer;
typedef struct s_gnl_line	t_gnl_line;

struct s_gnl_buffer
{
	int				fd;
	char			buffer[BUFFER_SIZE + 1];
	ssize_t			read_size;
	ssize_t			pos;
	t_gnl_buffer	*next;
};

struct s_gnl_line
{
	char	*line;
	size_t	length;
	size_t	size;
};

#endif
