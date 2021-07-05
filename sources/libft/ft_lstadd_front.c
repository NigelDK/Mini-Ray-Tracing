/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 16:39:38 by nde-koni          #+#    #+#             */
/*   Updated: 2020/09/16 20:37:00 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list *chain;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else if (*lst && new)
	{
		chain = *lst;
		new->next = chain;
		*lst = new;
	}
}
