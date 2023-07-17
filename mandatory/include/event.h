/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 04:01:25 by juwkim            #+#    #+#             */
/*   Updated: 2023/07/17 05:57:02 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "cub3d.h"

int	key_down(int keycode, t_cub3d *cub3d);
int	key_up(int keycode, t_cub3d *cub3d);
int	destroy(t_cub3d *cub3d);

#endif // __EVENT_H__
