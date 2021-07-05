/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_tr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:20:16 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 21:32:39 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vect	get_colour(t_view view, t_li li, t_vect colour, t_vect n)
{
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

t_vect			get_light_tr(t_world world, t_view view, t_li li)
{
	t_vect	start;
	t_vect	n;
	t_vect	colour;
	t_vect	v1;
	t_vect	v2;

	colour = v_init(0, 0, 0);
	start = v_add(view.ray.ori, v_scale(view.t, view.ray.dir));
	v1 = v_sub(world.tr[view.obj_nr].c1, world.tr[view.obj_nr].c0);
	v2 = v_sub(world.tr[view.obj_nr].c2, world.tr[view.obj_nr].c0);
	n = v_cross(v1, v2);
	if (v_dot(v_unit(n), view.ray.dir) < 1)
		n = v_cross(v2, v1);
	if (v_dot(n, n) == 0)
		return (colour);
	n = v_unit(n);
	if (v_dot(n, view.ray.dir) > 0)
		n = v_scale(-1, n);
	view.ray.dir = v_sub(li.ori, start);
	return (get_colour(view, li, colour, n));
}
