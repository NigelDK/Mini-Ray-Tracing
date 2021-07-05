/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:32:31 by nde-koni          #+#    #+#             */
/*   Updated: 2020/09/08 16:51:47 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned char	c1;

	c1 = (unsigned char)c;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (n--)
	{
		*dst1 = *src1;
		if (*src1 == c1)
			return (++dst1);
		dst1++;
		src1++;
	}
	return (0);
}
