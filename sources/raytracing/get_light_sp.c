/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:01:10 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 20:43:00 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vect	get_ambi_light(t_world world)
{
	world.ali.col.x *= world.ali.ratio / 255;
	world.ali.col.y *= world.ali.ratio / 255;
	world.ali.col.z *= world.ali.ratio / 255;
	return (world.ali.col);
}

t_vect	get_light_sp(t_world world, t_view view, t_li li)
{
	t_vect	start;
	t_vect	n;
	t_vect	colour;
	t_vect	dist;

	colour = v_init(0, 0, 0);
	start = v_add(view.ray.ori, v_scale(view.t, view.ray.dir));
	dist = v_sub(view.ray.ori, world.sp[view.obj_nr].c);
	n = v_sub(start, world.sp[view.obj_nr].c);
	if (sqrtf(v_dot(dist, dist)) <= world.sp[view.obj_nr].r)
		n = v_scale(-1, n);
	if (v_dot(n, n) == 0)
		return (colour);
	n = v_unit(n);
	view.ray.dir = v_sub(li.ori, start);
	if (v_dot(n, view.ray.dir) <= 0.0f)
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
