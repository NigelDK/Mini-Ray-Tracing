/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ali.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:35:26 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/20 15:26:23 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	parse_ali(char *line, t_data *img)
{
	char	**tab_a;
	char	**tab_b;

	char_err(img, line, "A");
	tab_a = ft_split(line, ' ');
	(tab_err(tab_a, 2)) ? ft_free_tab(img, &tab_a, 1, "A") : (0);
	(dot_err(tab_a[0], 1)) ? (ft_free_tab(img, &tab_a, 1, "A")) : (0);
	(comma_err(tab_a[0], 0)) ? (ft_free_tab(img, &tab_a, 1, "A")) : (0);
	img->world.ali.ratio = ft_atof(tab_a[0]);
	if (range_err(img->world.ali.ratio, 0.0, 1.0) || comma_err(tab_a[1], 2))
		ft_free_tab(img, &tab_a, 1, "A");
	tab_b = ft_split(tab_a[1], ',');
	ft_free_tab(img, &tab_a, 0, "");
	if (tab_err(tab_b, 3))
		ft_free_tab(img, &tab_b, 1, "A");
	if (dot_err(tab_b[0], 0) || dot_err(tab_b[1], 0) || dot_err(tab_b[2], 0))
		ft_free_tab(img, &tab_b, 1, "A");
	img->world.ali.col = v_init(ft_atof(tab_b[0]), ft_atof(tab_b[1]),
			ft_atof(tab_b[2]));
	if (range_err(img->world.ali.col.x, 0, 255) ||
			range_err(img->world.ali.col.y, 0, 255) ||
				range_err(img->world.ali.col.z, 0, 255))
		ft_free_tab(img, &tab_b, 1, "A");
	ft_free_tab(img, &tab_b, 0, "");
}
