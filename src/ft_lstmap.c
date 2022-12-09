/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:15:37 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/09 13:28:20 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_node;
	t_list	*new_lst;
	void	*new_data;

	if (lst == NULL)
		return (NULL);
	head_node = ft_memset(head_node, 0, sizeof(t_list *));
	new_lst = head_node->next;
	while (lst != NULL)
	{
		new_data = f(lst->content);
		new_lst = ft_lstnew(new_data);
		if (new_lst == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		lst = lst->next;
		new_lst = new_lst->next;
	}
	return (head_node);
}
