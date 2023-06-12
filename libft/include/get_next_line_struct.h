/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_struct.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:01:51 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/12 11:03:06 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_STRUCT_H
# define GET_NEXT_LINE_STRUCT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>

typedef struct s_buffer	t_buffer;
typedef struct s_line	t_line;

struct s_buffer
{
	int			fd;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		read_size;
	ssize_t		pos;
	t_buffer	*next;
};

struct s_line
{
	char	*line;
	size_t	len;
	size_t	size;
};

#endif
