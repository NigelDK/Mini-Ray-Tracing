/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_sq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:24:47 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 20:26:29 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vect	get_light_sq(t_world world, t_view view, t_li li)
{
	t_vect	start;
	t_vect	n;
	t_vect	colour;
	t_vect	dir;

	dir = v_init(0, 0, 1);
	ft_rotation(&dir, world.sq[view.obj_nr].orient);
	colour = v_init(0, 0, 0);
	start = v_add(view.ray.ori, v_scale(view.t, view.ray.dir));
	n = dir;
	if (v_dot(n, n) == 0)
		return (colour);
	if (v_dot(n, view.ray.dir) > 0)
		n = v_scale(-1, n);
	view.ray.dir = v_sub(li.ori, start);
	if (v_dot(n, view.ray.dir) <= 0)
		return (colour);
	view.t = sqrtf(v_dot(view.ray.dir, view.ray.dir));
	if (view.t <= 0.0f)
		return (colour);
	view.ray.dir = v_scale((1 / view.t), view.ray.dir);
	colour.x = v_dot(view.ray.dir, n) * li.col.x * li.ratio / 255;
	colour.y = v_dot(view.ray.dir, n) * li.col.y * li.ratio / 255;
	colour.z = v_dot(view.ray.dir, n) * li.col.z * li.ratio / 255;
	return (colour);
}
