/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 12:08:06 by nde-koni          #+#    #+#             */
/*   Updated: 2020/09/16 20:13:26 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*chain;
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	chain = *lst;
	while (chain)
	{
		temp = (chain)->next;
		ft_lstdelone(chain, del);
		chain = temp;
	}
	*lst = NULL;
}
