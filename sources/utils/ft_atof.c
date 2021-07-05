/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:07:11 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 15:06:19 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ft_dotstart(float *t0, char *s, char *tab)
{
	int	i;

	i = ft_strlen(tab);
	t0[0] = (float)ft_atoi(tab);
	if (s[0] == '.')
		while (i-- > 0)
			t0[0] /= 10;
}

float		ft_atof(char *s)
{
	char	**tab;
	float	t0;
	float	t1;
	int		i;

	tab = ft_split(s, '.');
	if (!tab[1])
	{
		ft_dotstart(&t0, s, tab[0]);
		ft_free_tabb(&tab);
		return (t0);
	}
	i = ft_strlen(tab[1]);
	t0 = (float)ft_atoi(tab[0]);
	t1 = (float)ft_atoi(tab[1]);
	ft_free_tabb(&tab);
	while (i-- > 0)
		t1 /= 10;
	if (s[0] == '-')
		return (-1 * (t0 + t1));
	return (t0 + t1);
}
