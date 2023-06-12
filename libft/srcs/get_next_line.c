/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:42:14 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/12 11:03:48 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "get_next_line.h"
#include "get_next_line_enum.h"

static int	init_tmp_line(t_line *line)
{
	line->line = malloc(sizeof(char));
	if (line->line == NULL)
		return (ERROR);
	line->len = 0;
	line->size = 1;
	return (SUCCESS);
}

static int	append_to_line(t_line *line, char c)
{
	char	*tmp;

	if (line->len == line->size)
	{
		tmp = malloc(sizeof(char) * (line->size * 2));
		if (tmp == NULL)
			return (ERROR);
		ft_memmove(tmp, line->line, line->len);
		free(line->line);
		line->line = tmp;
		line->size *= 2;
	}
	line->line[line->len++] = c;
	return (SUCCESS);
}

static int	get_line(t_buffer **buf, t_line *line, int fd)
{
	t_buffer	*cur;
	char		c;

	cur = get_node_or_null(buf, fd);
	if (cur == NULL)
		return (ERROR);
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
			return (ERROR);
		if (append_to_line(line, c) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static char	*remove_margine(t_line *line)
{
	char	*result;

	if (line->len == 0)
		return (NULL);
	result = malloc(sizeof(char) * (line->len + 1));
	if (result == NULL)
		return (NULL);
	ft_memmove(result, line->line, line->len);
	result[line->len] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static t_buffer	*lst;
	t_line			tmp_line;
	char			*read_line;

	if (read(fd, NULL, 0) == -1)
	{
		ft_lst_remove_if(&lst, fd);
		return (NULL);
	}
	if (init_tmp_line(&tmp_line) == ERROR)
	{
		ft_lst_remove_if(&lst, fd);
		return (NULL);
	}
	if (get_line(&lst, &tmp_line, fd) == ERROR)
	{
		ft_lst_remove_if(&lst, fd);
		free(tmp_line.line);
		tmp_line.line = NULL;
		return (NULL);
	}
	read_line = remove_margine(&tmp_line);
	free(tmp_line.line);
	tmp_line.line = NULL;
	return (read_line);
}
