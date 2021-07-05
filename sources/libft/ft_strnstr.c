/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 17:11:07 by nde-koni          #+#    #+#             */
/*   Updated: 2020/07/29 22:15:13 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (*s2 == 0 || s2 == 0)
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		while (i + j < n && s1[i + j] == s2[j])
		{
			j++;
			if (s2[j] == 0)
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (0);
}
