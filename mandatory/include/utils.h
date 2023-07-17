/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 07:08:17 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 03:40:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

bool	is_extension(const char *filename, const char *extension);
void	_assert(bool expr, const char *str);
int		_atoi(const char *nptr);

#endif // __UTILS_H__
