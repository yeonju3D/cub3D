/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:31:21 by yeongo            #+#    #+#             */
/*   Updated: 2022/07/07 15:49:02 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	if (n == 0)
		return ;
	tmp = (unsigned char *)s;
	while (n--)
	{
		*tmp = 0;
		tmp++;
	}
}
