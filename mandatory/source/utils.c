/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 07:07:29 by juwkim            #+#    #+#             */
/*   Updated: 2023/06/28 07:08:01 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_extension(const char *filename, const char *extension)
{
	const size_t	file_len = ft_strlen(filename);
	const size_t	extension_len = ft_strlen(extension);

	return (file_len > extension_len && \
		ft_strstr(filename + file_len - extension_len, extension));
}
