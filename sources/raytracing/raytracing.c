/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:27:24 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/23 11:07:36 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	make_img(t_data *img, t_cam cam, int x, int y)
{
	img->view.t = FLT_MAX;
	img->view.colobj = img->world.col;
	img->view.ray = cam_ray(x, y, cam);
	if (hit_obj(img->world, &img->view))
		img->view.colobj = get_light(img->world, img->view, img->li,
			img->li_cnt);
	my_mlx_pixel_put(img, x, y, (int)img->view.colobj.x << 16 |
			(int)img->view.colobj.y << 8 | (int)img->view.colobj.z);
}

void		raytracing(t_data *img)
{
	int		x;
	int		y;
	t_cam	cam;

	if (img->cam_loc == img->cam_cnt)
		img->cam_loc = 0;
	img->cam[img->cam_loc].w = img->world.width;
	img->cam[img->cam_loc].h = img->world.height;
	cam = img->cam[img->cam_loc++];
	y = 0;
	while (y < img->world.height)
	{
		x = 0;
		while (x < img->world.width)
		{
			make_img(img, cam, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
