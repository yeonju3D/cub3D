/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:50:40 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/21 20:51:48 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include <limits.h>
#include <stdbool.h>

static bool	ft_issign_for_atoi(int c, int *sign)
{
	if (ft_issign(c))
	{
		if (c == '-')
			*sign *= -1;
		return (true);
	}
	return (false);
}

int	ft_atoi(const char *str, int *result)
{
	int			sign;
	int			in_range;
	long long	result_tmp;

	sign = 1;
	in_range = 1;
	result_tmp = 0;
	while (ft_isspace(*str) == true)
		str++;
	if (ft_issign_for_atoi(*str, &sign) == true)
		str++;
	while (ft_isdigit(*str) == true)
	{
		result_tmp = 10 * result_tmp + (sign * (*str - '0'));
		if (result_tmp < INT_MIN || result_tmp > INT_MAX)
			in_range = 0;
		str++;
	}
	*result = result_tmp;
	return (in_range);
}
