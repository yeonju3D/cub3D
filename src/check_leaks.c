/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_leaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:38:19 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/13 08:19:03 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_memory.h"
#include "../include/ft_string.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	i_wanna_go_home(void)
{
	char	*str;

	str = ft_strjoin("leaks ", MANDA_NAME);
	system(str);
	free(str);
}

void	i_wanna_go_home_bonus(void)
{
	char	*str;

	str = ft_strjoin("leaks ", BONUS_NAME);
	system(str);
	free(str);
}
