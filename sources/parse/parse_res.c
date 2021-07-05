/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:19:35 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/22 15:15:32 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	parse_res(char *line, t_data *img)
{
	char	**tab;

	char_err(img, line, "R");
	tab = ft_split(line, ' ');
	if (tab_err(tab, 2) || dot_err(tab[0], 0) || dot_err(tab[1], 0) ||
			comma_err(tab[0], 0) || comma_err(tab[1], 0))
		ft_free_tab(img, &tab, 1, "R");
	img->world.width = ft_atoi(tab[0]);
	img->world.height = ft_atoi(tab[1]);
	if (img->world.width <= 200 || img->world.height <= 100)
		ft_free_tab(img, &tab, 1, "R\nMinimum Resolution is 200x100");
	ft_free_tab(img, &tab, 0, "");
}
