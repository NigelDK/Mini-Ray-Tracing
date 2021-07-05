/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cydisk2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 17:54:24 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 20:26:11 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ft_hit(t_world world, t_view *view, float t)
{
	view->t = t;
	view->obj = 5;
	view->colobj = world.cy[world.cy_cnt].col;
	view->obj_nr = world.cy_cnt;
}

bool		hit_cydisk2(t_world world, t_view *view)
{
	float	t;
	float	angle;
	t_vect	newstart;
	t_vect	v;
	t_vect	point;

	world.cy[world.cy_cnt].orient = v_unit(world.cy[world.cy_cnt].orient);
	point = v_add(world.cy[world.cy_cnt].c, v_scale(world.cy[world.cy_cnt].h,
			world.cy[world.cy_cnt].orient));
	angle = v_dot(view->ray.dir, world.cy[world.cy_cnt].orient);
	if (fabsf(angle) <= 0.001f)
		return (false);
	t = v_dot(v_sub(point, view->ray.ori),
			world.cy[world.cy_cnt].orient) / angle;
	if (t >= 0.01f && t < view->t)
	{
		newstart = v_add(view->ray.ori, v_scale(t, view->ray.dir));
		v = v_sub(newstart, point);
		if (sqrtf(v_dot(v, v)) <= world.cy[world.cy_cnt].d / 2 + 0.1)
		{
			ft_hit(world, view, t);
			return (true);
		}
	}
	return (false);
}
