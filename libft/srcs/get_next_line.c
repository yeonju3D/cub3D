/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:42:14 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/21 21:07:53 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "get_next_line.h"
#include "gnl_enum.h"
#include <stdlib.h>
#include <stdbool.h>

static bool	init_tmp_line(t_gnl_line *line)
{
	line->line = malloc(sizeof(char));
	if (line->line == NULL)
		return (false);
	line->line[0] = '\0';
	line->length = 0;
	line->size = 1;
	return (true);
}

static bool	append_to_line(t_gnl_line *line, char c)
{
	char	*tmp;

	if (line->length == line->size)
	{
		tmp = malloc(sizeof(char) * (line->size * 2));
		if (tmp == NULL)
			return (false);
		ft_memmove(tmp, line->line, line->length);
		free(line->line);
		line->line = tmp;
		line->size *= 2;
	}
	line->line[line->length++] = c;
	return (true);
}

static bool	get_line(t_gnl_buffer **buf, t_gnl_line *line, int fd)
{
	t_gnl_buffer	*cur;
	char			c;

	cur = get_node_or_null(buf, fd);
	if (cur == NULL)
		return (false);
	c = 0;
	while (c != '\n')
	{
		c = get_char(cur);
		if (cur->read_size == 0)
		{
			ft_lst_remove_if(buf, fd);
			break ;
		}
		else if (cur->read_size == -1)
			return (false);
		if (append_to_line(line, c) == false)
			return (false);
	}
	return (true);
}

static char	*trim_margine(t_gnl_line *line)
{
	char	*result;

	if (line->length == 0)
		return (NULL);
	result = malloc(sizeof(char) * (line->length + 1));
	if (result == NULL)
		return (NULL);
	ft_memmove(result, line->line, line->length);
	result[line->length] = '\0';
	return (result);
}

int	get_next_line(char **read_line, int fd)
{
	static t_gnl_buffer	*lst;
	t_gnl_line			tmp_line;

	if (read(fd, NULL, 0) == -1 \
		|| init_tmp_line(&tmp_line) == false)
	{
		ft_lst_remove_if(&lst, fd);
		return (FAIL);
	}
	if (get_line(&lst, &tmp_line, fd) == false)
	{
		ft_lst_remove_if(&lst, fd);
		free(tmp_line.line);
		tmp_line.line = NULL;
		return (FAIL);
	}
	*read_line = trim_margine(&tmp_line);
	free(tmp_line.line);
	tmp_line.line = NULL;
	return (SUCCESS);
}
