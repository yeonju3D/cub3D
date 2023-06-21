/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:21:27 by yeongo            #+#    #+#             */
/*   Updated: 2023/06/21 20:55:44 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

# include <stdbool.h>

bool	ft_isalpha(int c);
bool	ft_isdigit(int c);
bool	ft_issign(int c);
bool	ft_isspace(int c);
bool	ft_isalnum(int c);
bool	ft_isascii(int c);
bool	ft_isprint(int c);
bool	ft_toupper(int c);
bool	ft_tolower(int c);

#endif // !FT_CTYPE_H
