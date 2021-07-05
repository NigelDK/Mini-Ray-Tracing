/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:17:37 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/20 15:27:32 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ft_tab_b(t_data *img, char ***tab_b, char ***tab_c, char ***tab_d)
{
	if (tab_err(tab_b[0], 3) || dot_err(tab_b[0][0], 1) ||
			dot_err(tab_b[0][1], 1) || dot_err(tab_b[0][2], 1))
	{
		ft_free_tab(img, tab_b, 0, "");
		ft_free_tab(img, tab_c, 0, "");
		ft_free_tab(img, tab_d, 1, "sq");
	}
	img->world.sq[img->world.sq_loc].c = v_init(ft_atof(tab_b[0][0]),
			ft_atof(tab_b[0][1]), ft_atof(tab_b[0][2]));
	ft_free_tab(img, tab_b, 0, "");
}

static void	ft_tab_c(t_data *img, char ***tab_c, char ***tab_d)
{
	if (tab_err(tab_c[0], 3) || dot_err(tab_c[0][0], 1) ||
			dot_err(tab_c[0][1], 1) || dot_err(tab_c[0][2], 1))
	{
		ft_free_tab(img, tab_c, 0, "");
		ft_free_tab(img, tab_d, 1, "sq");
	}
	img->world.sq[img->world.sq_loc].orient = v_init(ft_atof(tab_c[0][0]),
			ft_atof(tab_c[0][1]), ft_atof(tab_c[0][2]));
	ft_free_tab(img, tab_c, 0, "");
	if (range_err(img->world.sq[img->world.sq_loc].orient.x, -1, 1) ||
			range_err(img->world.sq[img->world.sq_loc].orient.y, -1, 1) ||
				range_err(img->world.sq[img->world.sq_loc].orient.z, -1, 1))
		ft_free_tab(img, tab_d, 1, "sq");
}

static void	ft_tab_d(t_data *img, char ***tab_d)
{
	if (tab_err(tab_d[0], 3))
		ft_free_tab(img, tab_d, 1, "sq");
	img->world.sq[img->world.sq_loc].col = v_init(ft_atof(tab_d[0][0]),
			ft_atof(tab_d[0][1]), ft_atof(tab_d[0][2]));
	if (range_err(img->world.sq[img->world.sq_loc].col.x, 0, 255) ||
			range_err(img->world.sq[img->world.sq_loc].col.y, 0, 255) ||
				range_err(img->world.sq[img->world.sq_loc].col.z, 0, 255))
		ft_free_tab(img, tab_d, 1, "sq");
	ft_free_tab(img, tab_d, 0, "");
}

void		parse_sq(char *line, t_data *img)
{
	char	**tab_a;
	char	**tab_b;
	char	**tab_c;
	char	**tab_d;

	char_err(img, line, "sq");
	tab_a = ft_split(line, ' ');
	if (tab_err(tab_a, 4) || comma_err(tab_a[0], 2) || comma_err(tab_a[1], 2) ||
			comma_err(tab_a[2], 0) || comma_err(tab_a[3], 2) ||
			dot_err(tab_a[2], 1) || dot_err(tab_a[3], 0))
		ft_free_tab(img, &tab_a, 1, "sq");
	img->world.sq[img->world.sq_loc].ss = ft_atof(tab_a[2]);
	tab_b = ft_split(tab_a[0], ',');
	tab_c = ft_split(tab_a[1], ',');
	tab_d = ft_split(tab_a[3], ',');
	ft_free_tab(img, &tab_a, 0, "");
	ft_tab_b(img, &tab_b, &tab_c, &tab_d);
	ft_tab_c(img, &tab_c, &tab_d);
	ft_tab_d(img, &tab_d);
	img->world.sq_loc++;
}
