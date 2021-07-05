/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:55:10 by nde-koni          #+#    #+#             */
/*   Updated: 2020/09/03 15:20:51 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_head;

	if (!lst || !f || !del)
		return (NULL);
	if (!(new = ft_lstnew((*f)(lst->content))))
		return (NULL);
	new_head = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (new_head);
}
