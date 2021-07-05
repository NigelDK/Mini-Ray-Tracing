/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 23:16:32 by nde-koni          #+#    #+#             */
/*   Updated: 2020/09/16 20:39:59 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*chain;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else if (lst && *lst)
	{
		chain = ft_lstlast(*lst);
		chain->next = new;
	}
}
