/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:32:04 by yeongo            #+#    #+#             */
/*   Updated: 2022/09/27 16:14:25 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	ft_putchar_count(char c, int *result)
{
	*result += 1;
	return (write(1, &c, 1));
}

int	ft_putstr_count(char *str, int *result)
{
	if (str == NULL)
	{
		*result += 6;
		return (write(1, "(null)", 6));
	}
	*result += ft_strlen(str);
	return (write(1, str, ft_strlen(str)));
}
