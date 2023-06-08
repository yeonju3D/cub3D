/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:13:59 by yeongo            #+#    #+#             */
/*   Updated: 2023/04/21 21:46:02 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_putnbr_count(int n, int *result)
{
	if (n == INT_MIN)
		return (ft_putstr_count("-2147483648", result));
	else if (n < 0)
	{
		if (ft_putchar_count('-', result) < 0)
			return (ERROR);
		return (ft_putnbr_count(n * -1, result));
	}
	else
	{
		if (n > 9)
			if (ft_putnbr_count(n / 10, result) < 0)
				return (ERROR);
		return (ft_putchar_count(n % 10 + 48, result));
	}
}

int	ft_putnbr_base_count(unsigned int n, int base, char flag, int *result)
{
	if (n > (unsigned int)(base - 1))
		if (ft_putnbr_base_count(n / base, base, flag, result) < 0)
			return (ERROR);
	if (flag == 'u')
		return (ft_putchar_count(BASE_10[n % base], result));
	else if (flag == 'x')
		return (ft_putchar_count(BASE_16_LOWER[n % base], result));
	else if (flag == 'X')
		return (ft_putchar_count(BASE_16_UPPER[n % base], result));
	else
		return (0);
}

int	ft_print_memory_count(unsigned long long addr, int *result)
{
	if (addr > 15)
		if (ft_print_memory_count(addr / 16, result) < 0)
			return (ERROR);
	return (ft_putchar_count(BASE_16_LOWER[addr % 16], result));
}
