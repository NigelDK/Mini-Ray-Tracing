/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cydisk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:37:25 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 20:08:46 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	hit_cypl(t_world world, t_view *view)
{
	t_vect	dist;
	float	angle;
	float	t0;

	world.cy[world.cy_cnt].orient = v_unit(world.cy[world.cy_cnt].orient);
	dist = v_sub(world.cy[world.cy_cnt].c, view->ray.ori);
	angle = v_dot(view->ray.dir, world.cy[world.cy_cnt].orient);
	if (fabsf(angle) <= 0)
		return (false);
	t0 = v_dot(dist, world.cy[world.cy_cnt].orient) / angle;
	if (t0 >= 0.01f && t0 < view->t)
	{
		view->t = t0;
		return (true);
	}
	return (false);
}

static bool	hit_disk(t_world world, t_view *view, float t0)
{
	t_vect	dist;
	float	scaldist;

	dist = v_sub(v_add(view->ray.ori, v_scale(view->t, view->ray.dir)),
				world.cy[world.cy_cnt].c);
	scaldist = sqrt(v_dot(dist, dist));
	if (scaldist <= (world.cy[world.cy_cnt].d / 2) + 0.1 && view->t > 0.01f &&
			view->t < t0)
	{
		view->obj = 5;
		view->colobj = world.cy[world.cy_cnt].col;
		view->obj_nr = world.cy_cnt;
		return (true);
	}
	return (false);
}

bool		hit_cydisk(t_world world, t_view *view)
{
	float	t0;

	t0 = view->t;
	if (hit_cypl(world, view))
	{
		if (hit_disk(world, view, t0))
			return (true);
		view->t = t0;
	}
	return (false);
}
