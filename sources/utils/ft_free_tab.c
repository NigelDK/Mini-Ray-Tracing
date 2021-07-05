/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:13:07 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/20 12:08:13 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ft_free_tab(t_data *img, char ***tab, int j, char *s)
{
	int	i;

	i = 0;
	while (tab[0][i])
	{
		free(tab[0][i]);
		tab[0][i] = NULL;
		i++;
	}
	free(tab[0]);
	tab[0] = NULL;
	if (j == 1)
	{
		ft_free_all(img, 0);
		printf("Error\nEncountered invalid input at %s\n", s);
		exit(0);
	}
}
