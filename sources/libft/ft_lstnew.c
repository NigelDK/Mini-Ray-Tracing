/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 16:11:23 by nde-koni          #+#    #+#             */
/*   Updated: 2020/09/01 16:46:54 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_struct;

	if (!(new_struct = malloc(sizeof(t_list))))
		return (NULL);
	new_struct->content = content;
	new_struct->next = NULL;
	return (new_struct);
}
