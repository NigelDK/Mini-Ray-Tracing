/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:16:05 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/22 19:16:30 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ray	cam_ray(int x, int y, t_cam cam)
{
	t_ray	ray;

	ray.ori = cam.vp;
	ray.dir = v_init(x + 0.5 - cam.w / 2, y + 0.5 - cam.h / 2, 0);
	if (cam.w > cam.h)
		ray.dir.z = cam.w;
	else
		ray.dir.z = cam.h;
	ray.dir.z = ray.dir.z / (2 * tan(cam.fov / 2));
	ray.dir = v_unit(ray.dir);
	ft_rotation(&ray.dir, cam.dir);
	ray.dir = v_scale(-1, ray.dir);
	ray.dir.x = -ray.dir.x;
	return (ray);
}
