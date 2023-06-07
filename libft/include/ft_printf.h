/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:12:05 by yeongo            #+#    #+#             */
/*   Updated: 2022/09/27 16:13:20 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BASE_10 "0123456789"
# define BASE_16_LOWER "0123456789abcdef"
# define BASE_16_UPPER "0123456789ABCDEF"

# define ERROR -1
# define END_OF_STR -2

int	ft_putchar_count(char c, int *result);
int	ft_putstr_count(char *str, int *result);
int	ft_putnbr_count(int n, int *result);
int	ft_putnbr_base_count(unsigned int n, int base, char flag, int *result);
int	ft_print_memory_count(unsigned long long addr, int *result);
int	ft_printf(const char *format, ...);

#endif 
