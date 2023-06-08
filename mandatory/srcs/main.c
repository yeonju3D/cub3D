/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:23:18 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/08 22:06:33 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include <libft.h>
#include <ft_string.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/errno.h>

int	valid_map_format(char *map_path)
{
	size_t	path_length;

	path_length = ft_strlen(map_path);
	return (ft_strnstr(map_path + path_length - 4, ".ber", 5) \
			&& path_length >= 5);
}

int	check_valid_argument(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (!valid_map_format(av[1]))
		return (0);
	return (1);
}

void	ft_puterr(char *err)
{
	ft_putendl_fd(err, STDERR_FILENO);
}

void	syscall_err(void)
{
	int	errno_bak;

	errno_bak = errno;
	perror(strerror(errno_bak));
}

int	open_file(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_puterr("");
		return (-1);
	}
	return (fd);
}

int	parse_map(char *map_path)
{
	int	fd;

	fd = open_file(map_path);
	if (fd == -1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	if (!check_valid_argument(ac, av))
		return (1);
	if (!parse_map(av[1]))
		return (1);
	return (0);
}
