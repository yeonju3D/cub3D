/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:15:37 by yeongo            #+#    #+#             */
/*   Updated: 2023/04/21 21:38:48 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_node;
	t_list	*new_lst;
	void	*new_data;

	if (lst == NULL)
		return (NULL);
	new_lst = malloc(sizeof(t_list));
	if (new_lst == NULL)
		return (NULL);
	head_node = new_lst;
	while (lst != NULL)
	{
		new_data = f(lst->content);
		new_lst->next = ft_lstnew(new_data);
		if (new_lst->next == NULL)
		{
			if (del != NULL)
				del(new_data);
			ft_lstclear(&head_node, del);
			return (NULL);
		}
		lst = lst->next;
		new_lst = new_lst->next;
	}
	return (head_node);
}
