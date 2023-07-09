/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:23:18 by yeongo            #+#    #+#             */
/*   Updated: 2023/07/09 17:53:03 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	main(int argc, char *argv[])
{
	t_cub3d	cub3d;
	int		fd;

	if (argc != 2 || is_extension(argv[1], ".cub") == false)
	{
		ft_dprintf(STDERR_FILENO, "Usage: .cub3D *.cub\n");
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(strerror(errno));
		return (EXIT_FAILURE);
	}
	ft_memset(&cub3d.map, 0, sizeof cub3d.map);
	cub3d.mlx_ptr = ft_mlx_init();
	if (parse(&cub3d, fd) == false)
	{
		ft_printf("Invalid map\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
