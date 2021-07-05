/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:27:57 by nde-koni          #+#    #+#             */
/*   Updated: 2020/09/04 18:46:48 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	tot_len;

	i = 0;
	j = 0;
	tot_len = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[j])
		j++;
	tot_len = i + j;
	if (i == dstsize)
		return (tot_len);
	j = 0;
	while (src[j] && i + j < dstsize - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (tot_len);
}
