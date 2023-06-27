/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:23:18 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/27 20:41:10 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"

static bool	is_extension(const char *filename, const char *extension);

int	main(int argc, char *argv[])
{
	t_cub3d	cub3d;
	int		fd;

	if (argc != 2 || is_extension(argv[1], ".cub") == false)
	{
		ft_dprintf(STDERR_FILENO, "Usage: .cub3D *.cub");
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(strerror(errno));
		return (EXIT_FAILURE);
	}
	ft_memset(&cub3d.map, 0, sizeof cub3d.map);
	if (parse_map(&cub3d, fd) == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static bool	is_extension(const char *filename, const char *extension)
{
	const size_t	file_len = ft_strlen(filename);
	const size_t	extension_len = ft_strlen(extension);

	return (file_len > extension_len && \
		ft_strstr(filename + file_len - extension_len, extension));
}
