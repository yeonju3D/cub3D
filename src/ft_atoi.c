/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:50:40 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/28 22:00:39 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <limits.h>

static int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

int	ft_atoi(const char *str, int *result)
{
	int			sign;
	int			err_num;
	long long	result_tmp;

	sign = 1;
	err_num = 0;
	result_tmp = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
		if (!ft_isdigit(*str))
			return (1);
	}
	while (ft_isdigit(*str))
	{
		result_tmp = 10 * result_tmp + (sign * (*str - '0'));
		if (result_tmp < INT_MIN || result_tmp > INT_MAX)
			err_num = 1;
		str++;
	}
	*result = result_tmp;
	return (err_num);
}
