/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:56:46 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/04 10:41:49 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	cur = *lst;
	while (cur != NULL)
	{
		tmp = cur->next;
		ft_lstdelone(cur, del);
		cur = tmp;
	}
	*lst = NULL;
}
