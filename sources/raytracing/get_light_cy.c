/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:19:09 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 19:28:55 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vect	get_dist(t_world world, t_view view)
{
	t_vect	u;
	t_vect	v;
	t_vect	point;

	u = v_sub(view.ray.ori, world.cy[view.obj_nr].c);
	v = v_scale(world.cy[view.obj_nr].h, v_unit(world.cy[view.obj_nr].orient));
	point = v_scale(v_dot(u, v) / pow(sqrtf(v_dot(v, v)), 2), v);
	point = v_add(world.cy[view.obj_nr].c, point);
	return (v_sub(view.ray.ori, point));
}

t_vect			get_light_cy(t_world world, t_view view, t_li li)
{
	t_vect	start;
	t_vect	n;
	t_vect	colour;
	t_vect	dist;

	colour = v_init(0, 0, 0);
	start = v_add(view.ray.ori, v_scale(view.t, view.ray.dir));
	dist = get_dist(world, view);
	n = v_unit(v_sub(v_sub(start, world.cy[view.obj_nr].c),
			v_scale(view.n, world.cy[view.obj_nr].orient)));
	if (sqrtf(v_dot(dist, dist)) <= world.cy[view.obj_nr].d / 2)
		n = v_scale(-1, n);
	if (v_dot(n, n) == 0)
		return (colour);
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

t_vect			get_light_dsk(t_world world, t_view view, t_li li)
{
	t_vect	start;
	t_vect	n;
	t_vect	colour;

	colour = v_init(0, 0, 0);
	start = v_add(view.ray.ori, v_scale(view.t, view.ray.dir));
	n = world.cy[view.obj_nr].orient;
	if (v_dot(n, n) == 0)
		return (colour);
	n = v_unit(n);
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
