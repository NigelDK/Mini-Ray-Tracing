/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:17:38 by nde-koni          #+#    #+#             */
/*   Updated: 2020/08/07 17:25:13 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (!s || !f)
		return (NULL);
	if (!(str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (*s)
	{
		str[i] = (*f)(i, *s);
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
