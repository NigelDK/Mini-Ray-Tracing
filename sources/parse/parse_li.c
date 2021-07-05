/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_li.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:55:23 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/20 15:27:55 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ft_tab_bc(t_data *img, char ***tab_b, char ***tab_c)
{
	if (tab_err(tab_b[0], 3) || dot_err(tab_b[0][0], 1) ||
			dot_err(tab_b[0][1], 1) || dot_err(tab_b[0][2], 1))
	{
		ft_free_tab(img, tab_b, 0, "");
		ft_free_tab(img, tab_c, 1, "l");
	}
	img->li[img->li_loc].ori = v_init(ft_atof(tab_b[0][0]),
			ft_atof(tab_b[0][1]), ft_atof(tab_b[0][2]));
	ft_free_tab(img, tab_b, 0, "");
	if (tab_err(tab_c[0], 3) || dot_err(tab_c[0][0], 0) ||
			dot_err(tab_c[0][1], 0) || dot_err(tab_c[0][2], 0))
		ft_free_tab(img, tab_c, 1, "l");
	img->li[img->li_loc].col = v_init(ft_atof(tab_c[0][0]),
			ft_atof(tab_c[0][1]), ft_atof(tab_c[0][2]));
	if (range_err(img->li[img->li_loc].col.x, 0, 255) ||
			range_err(img->li[img->li_loc].col.y, 0, 255) ||
				range_err(img->li[img->li_loc].col.z, 0, 255))
		ft_free_tab(img, tab_c, 1, "l");
	ft_free_tab(img, tab_c, 0, "");
	img->li_loc++;
}

void	parse_li(char *line, t_data *img)
{
	char	**tab_a;
	char	**tab_b;
	char	**tab_c;

	char_err(img, line, "l");
	tab_a = ft_split(line, ' ');
	if (tab_err(tab_a, 3) || comma_err(tab_a[0], 2) || comma_err(tab_a[2], 2) ||
			comma_err(tab_a[1], 0) || dot_err(tab_a[1], 1))
		ft_free_tab(img, &tab_a, 1, "l");
	img->li[img->li_loc].ratio = ft_atof(tab_a[1]);
	if (range_err(img->li[img->li_loc].ratio, 0.0, 1.0))
		ft_free_tab(img, &tab_a, 1, "l");
	tab_b = ft_split(tab_a[0], ',');
	tab_c = ft_split(tab_a[2], ',');
	ft_free_tab(img, &tab_a, 0, "");
	ft_tab_bc(img, &tab_b, &tab_c);
}
