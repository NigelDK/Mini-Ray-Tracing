/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:20:07 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/23 12:58:59 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ft_tab_d(t_data *img, char ***tab_d)
{
	if (range_err(img->world.pl[img->world.cy_loc].orient.x, -1, 1) ||
			range_err(img->world.pl[img->world.cy_loc].orient.y, -1, 1) ||
				range_err(img->world.pl[img->world.cy_loc].orient.z, -1, 1))
		ft_free_tab(img, tab_d, 1, "pl");
	if (tab_err(tab_d[0], 3) || dot_err(tab_d[0][0], 0) ||
			dot_err(tab_d[0][1], 0) || dot_err(tab_d[0][2], 0))
		ft_free_tab(img, tab_d, 1, "pl");
	img->world.pl[img->world.pl_loc].col = v_init(ft_atof(tab_d[0][0]),
			ft_atof(tab_d[0][1]), ft_atof(tab_d[0][2]));
	if (range_err(img->world.pl[img->world.pl_loc].col.x, 0, 255) ||
			range_err(img->world.pl[img->world.pl_loc].col.y, 0, 255) ||
				range_err(img->world.pl[img->world.pl_loc].col.z, 0, 255))
		ft_free_tab(img, tab_d, 1, "pl");
	ft_free_tab(img, tab_d, 0, "");
}

static void	ft_tab_bc(t_data *img, char ***tab_b, char ***tab_c, char ***tab_d)
{
	if (tab_err(tab_b[0], 3) || dot_err(tab_b[0][0], 1) ||
			dot_err(tab_b[0][1], 1) || dot_err(tab_b[0][2], 1))
	{
		ft_free_tab(img, tab_b, 0, "");
		ft_free_tab(img, tab_c, 0, "");
		ft_free_tab(img, tab_d, 1, "pl");
	}
	img->world.pl[img->world.pl_loc].c = v_init(ft_atof(tab_b[0][0]),
			ft_atof(tab_b[0][1]), ft_atof(tab_b[0][2]));
	ft_free_tab(img, tab_b, 0, "");
	if (tab_err(tab_c[0], 3) || dot_err(tab_c[0][0], 1) ||
			dot_err(tab_c[0][1], 1) || dot_err(tab_c[0][2], 1))
	{
		ft_free_tab(img, tab_c, 0, "");
		ft_free_tab(img, tab_d, 1, "pl");
	}
	img->world.pl[img->world.pl_loc].orient = v_init(ft_atof(tab_c[0][0]),
			ft_atof(tab_c[0][1]), ft_atof(tab_c[0][2]));
	ft_free_tab(img, tab_c, 0, "");
}

void		parse_pl(char *line, t_data *img)
{
	char	**tab_a;
	char	**tab_b;
	char	**tab_c;
	char	**tab_d;
	t_vect	dir;

	char_err(img, line, "pl");
	tab_a = ft_split(line, ' ');
	if (tab_err(tab_a, 3))
		ft_free_tab(img, &tab_a, 1, "pl");
	if (comma_err(tab_a[0], 2) || comma_err(tab_a[1], 2) ||
			comma_err(tab_a[2], 2))
		ft_free_tab(img, &tab_a, 1, "pl");
	tab_b = ft_split(tab_a[0], ',');
	tab_c = ft_split(tab_a[1], ',');
	tab_d = ft_split(tab_a[2], ',');
	ft_free_tab(img, &tab_a, 0, "");
	ft_tab_bc(img, &tab_b, &tab_c, &tab_d);
	ft_tab_d(img, &tab_d);
	dir = v_init(0, 0, 1);
	ft_rotation(&dir, img->world.pl[img->world.pl_loc].orient);
	img->world.pl[img->world.pl_loc].orient = dir;
	img->world.pl_loc++;
}
