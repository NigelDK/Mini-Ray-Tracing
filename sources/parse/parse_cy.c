/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:31:55 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/20 15:28:00 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ft_tab_a(t_data *img, char ***tab_a)
{
	if (tab_err(tab_a[0], 5))
		ft_free_tab(img, tab_a, 1, "cy");
	if (comma_err(tab_a[0][2], 0) || comma_err(tab_a[0][3], 0) ||
			dot_err(tab_a[0][2], 1) || dot_err(tab_a[0][3], 1))
		ft_free_tab(img, tab_a, 1, "cy");
	if (comma_err(tab_a[0][0], 2) || comma_err(tab_a[0][1], 2) ||
			comma_err(tab_a[0][4], 2))
		ft_free_tab(img, tab_a, 1, "cy");
	img->world.cy[img->world.cy_loc].d = ft_atof(tab_a[0][2]);
	img->world.cy[img->world.cy_loc].h = ft_atof(tab_a[0][3]);
}

static void	ft_tab_b(t_data *img, char ***tab_b, char ***tab_c, char ***tab_d)
{
	if (dot_err(tab_b[0][0], 1) || dot_err(tab_b[0][1], 1) ||
			dot_err(tab_b[0][2], 1))
	{
		ft_free_tab(img, tab_b, 0, "");
		ft_free_tab(img, tab_c, 0, "");
		ft_free_tab(img, tab_d, 1, "cy");
	}
	img->world.cy[img->world.cy_loc].c = v_init(ft_atof(tab_b[0][0]),
			ft_atof(tab_b[0][1]), ft_atof(tab_b[0][2]));
	ft_free_tab(img, tab_b, 0, "");
}

static void	ft_tab_c(t_data *img, char ***tab_c, char ***tab_d)
{
	if (dot_err(tab_c[0][0], 1) || dot_err(tab_c[0][1], 1) ||
			dot_err(tab_c[0][2], 1))
	{
		ft_free_tab(img, tab_c, 0, "");
		ft_free_tab(img, tab_d, 1, "cy");
	}
	img->world.cy[img->world.cy_loc].orient = v_init(ft_atof(tab_c[0][0]),
			ft_atof(tab_c[0][1]), ft_atof(tab_c[0][2]));
	if (range_err(img->world.cy[img->world.cy_loc].orient.x, -1, 1) ||
			range_err(img->world.cy[img->world.cy_loc].orient.y, -1, 1) ||
				range_err(img->world.cy[img->world.cy_loc].orient.z, -1, 1))
	{
		ft_free_tab(img, tab_c, 0, "");
		ft_free_tab(img, tab_d, 1, "cy");
	}
	ft_free_tab(img, tab_c, 0, "");
}

static void	ft_tab_d(t_data *img, char ***tab_d)
{
	if (dot_err(tab_d[0][0], 0) || dot_err(tab_d[0][1], 0) ||
			dot_err(tab_d[0][2], 0))
		ft_free_tab(img, tab_d, 1, "cy");
	img->world.cy[img->world.cy_loc].col = v_init(ft_atof(tab_d[0][0]),
			ft_atof(tab_d[0][1]), ft_atof(tab_d[0][2]));
	if (range_err(img->world.cy[img->world.cy_loc].col.x, 0, 255) ||
			range_err(img->world.cy[img->world.cy_loc].col.y, 0, 255) ||
				range_err(img->world.cy[img->world.cy_loc].col.z, 0, 255))
		ft_free_tab(img, tab_d, 1, "cy");
	ft_free_tab(img, tab_d, 0, "");
}

void		parse_cy(char *line, t_data *img)
{
	char	**tab_a;
	char	**tab_b;
	char	**tab_c;
	char	**tab_d;
	t_vect	dir;

	char_err(img, line, "cy");
	tab_a = ft_split(line, ' ');
	ft_tab_a(img, &tab_a);
	tab_b = ft_split(tab_a[0], ',');
	tab_c = ft_split(tab_a[1], ',');
	tab_d = ft_split(tab_a[4], ',');
	ft_free_tab(img, &tab_a, 0, "");
	ft_tab_b(img, &tab_b, &tab_c, &tab_d);
	ft_tab_c(img, &tab_c, &tab_d);
	ft_tab_d(img, &tab_d);
	dir = v_init(0, 0, 1);
	ft_rotation(&dir, img->world.cy[img->world.cy_loc].orient);
	img->world.cy[img->world.cy_loc].orient = dir;
	img->world.cy_loc++;
}
