/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:58:54 by yeongo            #+#    #+#             */
/*   Updated: 2023/01/05 13:20:21 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_abs_int(int nbr)
{
	unsigned int	abs_nbr;

	if (nbr < 0)
		abs_nbr = nbr * -1;
	else
		abs_nbr = nbr;
	return (abs_nbr);
}
