/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:10:31 by yeongo            #+#    #+#             */
/*   Updated: 2022/09/28 09:58:32 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define SUCCESS 0
# define ERROR -1
# define READ_EOF -2

# include <unistd.h>
# include <stdlib.h>

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

void		ft_lst_remove_if(t_buffer **lst, int fd);
t_buffer	*get_node_or_null(t_buffer **lst, int fd);
char		get_char(t_buffer *buf);
char		*get_next_line(int fd);

#endif
