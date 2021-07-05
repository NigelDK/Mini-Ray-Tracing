/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_tr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:42:10 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 20:56:12 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	ft_hit(t_world world, t_view *view, float t0)
{
	if ((t0 >= 0.1f) && (t0 < view->t))
	{
		view->obj = 3;
		view->t = t0;
		view->colobj = world.tr[world.tr_cnt].col;
		view->obj_nr = world.tr_cnt;
		return (true);
	}
	return (false);
}

bool		hit_tr(t_world world, t_view *view)
{
	t_vect	v1;
	t_vect	v2;
	t_vect	abc;
	float	t0;

	v1 = v_sub(world.tr[world.tr_cnt].c1, world.tr[world.tr_cnt].c0);
	v2 = v_sub(world.tr[world.tr_cnt].c2, world.tr[world.tr_cnt].c0);
	if (fabsf(v_dot(v1, v_cross(view->ray.dir, v2))) <= 0)
		return (false);
	abc.z = 1 / v_dot(v1, v_cross(view->ray.dir, v2));
	abc.x = v_dot(v_sub(view->ray.ori, world.tr[world.tr_cnt].c0),
					v_cross(view->ray.dir, v2)) * abc.z;
	abc.y = v_dot(view->ray.dir, v_cross(v_sub(view->ray.ori,
					world.tr[world.tr_cnt].c0), v1)) * abc.z;
	if (abc.y < 0 || abc.x + abc.y > 1 || abc.x < 0 || abc.x > 1)
		return (false);
	t0 = v_dot(v2, v_cross(v_sub(view->ray.ori,
				world.tr[world.tr_cnt].c0), v1)) * abc.z;
	return (ft_hit(world, view, t0));
}
