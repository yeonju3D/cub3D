/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 07:07:29 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 13:14:23 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_extension(const char *filename, const char *extension)
{
	const size_t	file_len = ft_strlen(filename);
	const size_t	extension_len = ft_strlen(extension);

	return (file_len > extension_len && \
		ft_strcmp(filename + file_len - extension_len, extension) == 0);
}

void	_assert(bool expr, const char *str)
{
	if (expr == false)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		ft_dprintf(STDERR_FILENO, str);
		exit(EXIT_FAILURE);
	}
}

int	_atoi(const char *nptr)
{
	int	num;
	int	sign;

	sign = 0;
	if (ft_strchr("+-", *nptr) != NULL)
		sign = (*nptr++ == '-');
	num = 0;
	while (ft_isdigit(*nptr) == true)
		num = num * 10 + (*nptr++ - '0');
	_assert(*nptr == '\0', "color includes nonnumeric character\n");
	if (sign == 1)
		return (-num);
	return (num);
}

int	_strfind(const char *s, char c)
{
	const char	*cur = s;

	while (*cur != '\0' && *cur != c)
		++cur;
	return (cur - s);
}
