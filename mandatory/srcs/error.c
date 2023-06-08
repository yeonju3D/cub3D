/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:14:29 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/08 22:15:36 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>

void	ft_puterr(char *err)
{
	ft_putendl_fd(err, STDERR_FILENO);
}

void	syscall_err(void)
{
	int	errno_bak;

	errno_bak = errno;
	perror(strerror(errno_bak));
}
