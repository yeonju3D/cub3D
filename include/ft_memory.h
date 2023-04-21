/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:39:55 by yeongo            #+#    #+#             */
/*   Updated: 2023/04/21 21:31:40 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stdlib.h>

void	*ft_calloc(size_t count, size_t size);
void	ft_free_str(char **str);
void	ft_free_strings(char ***strings);
void	ft_free_void(void ***ptr, int index_max);
void	i_wanna_go_home(void);

#endif
