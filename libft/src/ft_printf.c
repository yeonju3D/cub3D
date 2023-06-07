/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 12:47:25 by yeongo            #+#    #+#             */
/*   Updated: 2023/04/21 21:39:34 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	convert_format(const char format, va_list ap, int *result)
{
	if (format == '\0')
		return (END_OF_STR);
	else if (format == 'c')
		return (ft_putchar_count((unsigned char)va_arg(ap, int), result));
	else if (format == '%')
		return (ft_putchar_count('%', result));
	else if (format == 's')
		return (ft_putstr_count(va_arg(ap, char *), result));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_count(va_arg(ap, int), result));
	else if (format == 'x' || format == 'X')
		return (ft_putnbr_base_count
			(va_arg(ap, unsigned int), 16, format, result));
	else if (format == 'u')
		return (ft_putnbr_base_count
			(va_arg(ap, unsigned int), 10, format, result));
	else if (format == 'p')
	{
		if (ft_putstr_count("0x", result) < 0)
			return (ERROR);
		return (ft_print_memory_count(va_arg(ap, unsigned long long), result));
	}
	else
		return (ft_putchar_count(format, result));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;
	int		check_err;

	va_start(ap, format);
	result = 0;
	check_err = 0;
	while (*format)
	{
		if (*format == '%')
			check_err = convert_format(*++format, ap, &result);
		else
			check_err = ft_putchar_count(*format, &result);
		if (check_err == END_OF_STR)
			break ;
		else if (check_err == ERROR)
		{
			va_end(ap);
			return (-1);
		}
		format++;
	}
	va_end(ap);
	return (result);
}
