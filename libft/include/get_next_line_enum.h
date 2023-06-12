/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_enum.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:00:45 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/12 11:01:43 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_ENUM_H
# define GET_NEXT_LINE_ENUM_H

enum e_read_result
{
	SUCCESS		= 0,
	ERROR		= -1,
	READ_EOF	= -2
};

#endif
