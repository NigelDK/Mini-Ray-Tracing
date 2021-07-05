/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:11:55 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 16:46:05 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_char(char const s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int		ft_strl(char const *s, char c)
{
	int	i;

	i = 0;
	while (!ft_char(*s++, c) && *s)
		i++;
	return (i);
}

static int		ft_words(char const *s, char c)
{
	int	i;

	i = 0;
	while (ft_char(*s, c) && *s)
		s++;
	while (*s)
	{
		while (!ft_char(*s, c) && *s)
			s++;
		while (ft_char(*s, c) && *s)
			s++;
		i++;
	}
	return (i);
}

static void		ft_free(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!s || !(tab = malloc((ft_words(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (ft_char(*s, c) && *s)
		s++;
	j = 0;
	while (*s && !(i = 0))
	{
		if (!(tab[j] = malloc((ft_strl(s, c) + 1) * sizeof(char *))))
		{
			ft_free(tab, j);
			return (NULL);
		}
		while (!ft_char(*s, c) && *s)
			tab[j][i++] = *s++;
		tab[j][i] = '\0';
		while (ft_char(*s, c) && *s)
			s++;
		j++;
	}
	tab[j] = 0;
	return (tab);
}
