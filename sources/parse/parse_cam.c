/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:14:20 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/22 14:06:40 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ft_rest(t_data *img, char ***tab_c)
{
	if (tab_err(tab_c[0], 3) || dot_err(tab_c[0][0], 1) ||
			dot_err(tab_c[0][1], 1) || dot_err(tab_c[0][2], 1))
		ft_free_tab(img, tab_c, 1, "c");
	img->cam[img->cam_loc].dir = v_init(ft_atof(tab_c[0][0]),
			ft_atof(tab_c[0][1]), ft_atof(tab_c[0][2]));
	if (range_err(img->cam[img->cam_loc].dir.x, -1, 1) ||
			range_err(img->cam[img->cam_loc].dir.y, -1, 1) ||
				range_err(img->cam[img->cam_loc].dir.z, -1, 1))
		ft_free_tab(img, tab_c, 1, "c");
	ft_free_tab(img, tab_c, 0, "");
	img->cam_loc++;
}

void		parse_cam(char *line, t_data *img)
{
	char	**tab_a;
	char	**tab_b;
	char	**tab_c;

	char_err(img, line, "c");
	tab_a = ft_split(line, ' ');
	if (tab_err(tab_a, 3) || comma_err(tab_a[0], 2) || comma_err(tab_a[1], 2))
		ft_free_tab(img, &tab_a, 1, "c");
	if (dot_err(tab_a[2], 0) || range_err((float)ft_atoi(tab_a[2]), 0, 180) ||
			comma_err(tab_a[2], 0))
		ft_free_tab(img, &tab_a, 1, "c");
	img->cam[img->cam_loc].fov = ft_atoi(tab_a[2]);
	tab_b = ft_split(tab_a[0], ',');
	tab_c = ft_split(tab_a[1], ',');
	ft_free_tab(img, &tab_a, 0, "");
	if (tab_err(tab_b, 3) || dot_err(tab_b[0], 1) || dot_err(tab_b[1], 1) ||
			dot_err(tab_b[2], 1))
		ft_free_tab(img, &tab_b, 1, "c");
	img->cam[img->cam_loc].vp = v_init(ft_atof(tab_b[0]), ft_atof(tab_b[1]),
			ft_atof(tab_b[2]));
	ft_free_tab(img, &tab_b, 0, "");
	ft_rest(img, &tab_c);
}
