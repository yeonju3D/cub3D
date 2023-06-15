/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:10:31 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/15 21:30:47 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "gnl_struct.h"

void			ft_lst_remove_if(t_gnl_buffer **lst, int fd);
t_gnl_buffer	*get_node_or_null(t_gnl_buffer **lst, int fd);
char			get_char(t_gnl_buffer *buf);
int				get_next_line(char **read_line, int fd);

#endif
