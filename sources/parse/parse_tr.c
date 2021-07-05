/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:34:06 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/22 14:09:07 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ft_tab_a(t_data *img, char *line, t_tabs *t)
{
	t->tab_a = ft_split(line, ' ');
	if (tab_err(t->tab_a, 4) || comma_err(t->tab_a[0], 2) ||
			comma_err(t->tab_a[1], 2) || comma_err(t->tab_a[2], 2) ||
				comma_err(t->tab_a[3], 2) || dot_err(t->tab_a[3], 0))
		ft_free_tab(img, &t->tab_a, 1, "tr");
}

static void	ft_bcde_check(t_data *img, t_tabs *t)
{
	if (tab_err(t->tab_b, 3) || dot_err(t->tab_b[0], 1) ||
			dot_err(t->tab_b[1], 1) || dot_err(t->tab_b[2], 1))
	{
		ft_free_tab(img, &t->tab_b, 0, "");
		ft_free_tab(img, &t->tab_c, 0, "");
		ft_free_tab(img, &t->tab_d, 0, "");
		ft_free_tab(img, &t->tab_e, 1, "tr");
	}
}

static void	ft_tab_c(t_data *img, t_tabs *t)
{
	if (tab_err(t->tab_c, 3) || dot_err(t->tab_c[0], 1) ||
			dot_err(t->tab_c[1], 1) || dot_err(t->tab_c[2], 1))
	{
		ft_free_tab(img, &t->tab_c, 0, "");
		ft_free_tab(img, &t->tab_d, 0, "");
		ft_free_tab(img, &t->tab_e, 1, "tr");
	}
	img->world.tr[img->world.tr_loc].c1 = v_init(ft_atof(t->tab_c[0]),
			ft_atof(t->tab_c[1]), ft_atof(t->tab_c[2]));
	ft_free_tab(img, &t->tab_c, 0, "");
}

static void	ft_tab_de(t_data *img, t_tabs *t)
{
	if (tab_err(t->tab_d, 3) || dot_err(t->tab_d[0], 1) ||
			dot_err(t->tab_d[1], 1) || dot_err(t->tab_d[2], 1))
	{
		ft_free_tab(img, &t->tab_d, 0, "");
		ft_free_tab(img, &t->tab_e, 1, "tr");
	}
	img->world.tr[img->world.tr_loc].c2 = v_init(ft_atof(t->tab_d[0]),
			ft_atof(t->tab_d[1]), ft_atof(t->tab_d[2]));
	ft_free_tab(img, &t->tab_d, 0, "");
	if (tab_err(t->tab_e, 3) || dot_err(t->tab_e[0], 1) ||
			dot_err(t->tab_e[1], 1) || dot_err(t->tab_e[2], 1))
		ft_free_tab(img, &t->tab_e, 1, "tr");
	img->world.tr[img->world.tr_loc].col = v_init(ft_atof(t->tab_e[0]),
			ft_atof(t->tab_e[1]), ft_atof(t->tab_e[2]));
	if (range_err(img->world.tr[img->world.tr_loc].col.x, 0, 255) ||
			range_err(img->world.tr[img->world.tr_loc].col.y, 0, 255) ||
				range_err(img->world.tr[img->world.tr_loc].col.z, 0, 255))
		ft_free_tab(img, &t->tab_e, 1, "tr");
	ft_free_tab(img, &t->tab_e, 0, "");
}

void		parse_tr(char *line, t_data *img)
{
	t_tabs	t;

	char_err(img, line, "tr");
	ft_tab_a(img, line, &t);
	t.tab_b = ft_split(t.tab_a[0], ',');
	t.tab_c = ft_split(t.tab_a[1], ',');
	t.tab_d = ft_split(t.tab_a[2], ',');
	t.tab_e = ft_split(t.tab_a[3], ',');
	ft_free_tab(img, &t.tab_a, 0, "");
	ft_bcde_check(img, &t);
	img->world.tr[img->world.tr_loc].c0 = v_init(ft_atof(t.tab_b[0]),
			ft_atof(t.tab_b[1]), ft_atof(t.tab_b[2]));
	ft_free_tab(img, &t.tab_b, 0, "");
	ft_tab_c(img, &t);
	ft_tab_de(img, &t);
	img->world.tr_loc++;
}
