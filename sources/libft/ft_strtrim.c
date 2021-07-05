/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:21:10 by nde-koni          #+#    #+#             */
/*   Updated: 2020/09/05 23:20:52 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		in_charset(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	find_begin(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (in_charset(s1[i], set))
		i++;
	return (i);
}

static size_t	find_end(char const *s1, char const *set)
{
	size_t i;

	i = ft_strlen(s1);
	if (i == 0)
		return (i);
	i--;
	while (i > 0 && in_charset(s1[i], set))
		i--;
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = find_begin(s1, set);
	j = find_end(s1, set);
	k = 0;
	if (j == 0)
		j = i;
	if (!(str = (char *)malloc(((j - i) + 2) * sizeof(char))))
		return (0);
	while (i <= j)
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	str[k] = 0;
	return (str);
}
