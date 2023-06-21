/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:59:12 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/21 20:54:42 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_issep(char c, char const *sep)
{
	while (*sep)
	{
		if (*sep == c)
			return (true);
		sep++;
	}
	return (false);
}
