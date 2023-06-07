/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:23:18 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/07 19:32:39 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid_map_format(char *map_path)
{
	return (1);
}

int	check_valid_argument(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (!valid_map_format(av[1]))
		return (0);
	return (1);
}

int	parse_map(char *map_path)
{
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
