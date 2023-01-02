/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:25:54 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/28 21:00:31 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_string.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			s_len;
	unsigned int	index;

	s_len = ft_strlen(s);
	index = 0;
	while (index < s_len)
	{
		f(index, &s[index]);
		index++;
	}
}
