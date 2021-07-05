/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 23:24:30 by nde-koni          #+#    #+#             */
/*   Updated: 2020/07/20 23:24:35 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s3;
	unsigned char *s4;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*s3 != *s4)
			return (*s3 - *s4);
		s3++;
		s4++;
		n--;
	}
	return (0);
}
