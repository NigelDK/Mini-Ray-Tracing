/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:20:29 by nde-koni          #+#    #+#             */
/*   Updated: 2020/09/04 23:43:38 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nr_len(int n)
{
	int			len;
	long int	nr;

	nr = n;
	len = 0;
	if (nr == 0)
		return (1);
	if (nr < 0)
	{
		nr = nr * -1;
		len++;
	}
	while (nr > 0)
	{
		nr /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nr;

	nr = n;
	i = ft_nr_len(nr);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (nr == 0)
	{
		str[i] = 48;
		return (str);
	}
	if (nr < 0)
	{
		str[0] = '-';
		nr *= -1;
	}
	while (nr > 0)
	{
		str[i--] = 48 + (nr % 10);
		nr /= 10;
	}
	return (str);
}
