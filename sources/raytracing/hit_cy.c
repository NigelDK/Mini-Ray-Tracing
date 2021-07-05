/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:31:08 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 20:00:19 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	get_tm_values(t_vect *dt1t2, t_vect *m0m1m2)
{
	if (dt1t2->y >= 0 && dt1t2->z >= 0)
	{
		(dt1t2->y > dt1t2->z) ? (m0m1m2->x = m0m1m2->z + 0.1) :
			(m0m1m2->x = m0m1m2->y + 0.1);
		(dt1t2->y > dt1t2->z) ? (dt1t2->y = dt1t2->z) : (0);
	}
	else
	{
		(dt1t2->y < 0) ? (m0m1m2->x = m0m1m2->z) :
			(m0m1m2->x = m0m1m2->y);
		(dt1t2->y < 0) ? (dt1t2->y = dt1t2->z) : (0);
	}
}

static bool	disc(t_world world, t_view *view, t_vect *dt1t2, t_vect *m0m1m2)
{
	t_vect	abc;
	t_vect	x;

	abc.x = v_dot(view->ray.dir, view->ray.dir) -
			pow(v_dot(view->ray.dir, world.cy[world.cy_cnt].orient), 2);
	x = v_sub(view->ray.ori, world.cy[world.cy_cnt].c);
	abc.y = (v_dot(view->ray.dir, x) - v_dot(view->ray.dir,
		world.cy[world.cy_cnt].orient) *
			v_dot(x, world.cy[world.cy_cnt].orient)) * 2;
	abc.z = v_dot(x, x) - pow(v_dot(x, world.cy[world.cy_cnt].orient), 2) -
		pow(world.cy[world.cy_cnt].d / 2, 2);
	dt1t2->x = abc.y * abc.y - 4 * abc.x * abc.z;
	if (dt1t2->x < 0.001f)
		return (false);
	dt1t2->y = (-abc.y + sqrtf(dt1t2->x)) / (2 * abc.x);
	dt1t2->z = (-abc.y - sqrtf(dt1t2->x)) / (2 * abc.x);
	m0m1m2->y = v_dot(view->ray.dir, v_scale(dt1t2->y,
		world.cy[world.cy_cnt].orient)) +
			v_dot(x, world.cy[world.cy_cnt].orient);
	m0m1m2->z = v_dot(view->ray.dir, v_scale(dt1t2->z,
		world.cy[world.cy_cnt].orient)) +
			v_dot(x, world.cy[world.cy_cnt].orient);
	get_tm_values(dt1t2, m0m1m2);
	return (true);
}

bool		hit_cy(t_world world, t_view *view)
{
	t_vect	dt1t2;
	t_vect	m0m1m2;

	world.cy[world.cy_cnt].orient = v_unit(world.cy[world.cy_cnt].orient);
	if (!disc(world, view, &dt1t2, &m0m1m2))
		return (false);
	if (m0m1m2.x > 0.1f && m0m1m2.x <= world.cy[world.cy_cnt].h)
		if (dt1t2.y > 0.1f && dt1t2.y < view->t)
		{
			view->obj = 4;
			view->t = dt1t2.y;
			view->colobj = world.cy[world.cy_cnt].col;
			view->obj_nr = world.cy_cnt;
			view->n = m0m1m2.x;
			return (true);
		}
	return (false);
}
