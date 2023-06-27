/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:39:40 by juwkim            #+#    #+#             */
/*   Updated: 2023/06/28 05:11:45 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/**
 * @brief 
 * Copy the string s.
 * @param s  
 * @return the copied string.
 */
char	*ft_strdup(const char *s)
{
	char		*copy;

	copy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (copy == NULL)
		return (NULL);
	ft_strcpy(copy, s);
	return (copy);
}
