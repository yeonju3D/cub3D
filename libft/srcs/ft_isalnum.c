/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:04:11 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/21 20:53:15 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include <stdbool.h>

bool	ft_isalnum(int c)
{
	if (ft_isdigit(c))
		return (true);
	return (ft_isalpha(c));
}
