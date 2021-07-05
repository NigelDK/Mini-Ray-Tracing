/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:28:15 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 21:32:50 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ft_hit(t_world world, t_view *view, t_vect dt0t1)
{
	view->obj = 1;
	view->t = dt0t1.y;
	view->colobj = world.sp[world.sp_cnt].col;
	view->obj_nr = world.sp_cnt;
}

bool		hit_sp(t_world world, t_view *view)
{
	t_vect	abc;
	t_vect	dt0t1;
	t_vect	dist;

	abc.x = v_dot(view->ray.dir, view->ray.dir);
	dist = v_sub(view->ray.ori, world.sp[world.sp_cnt].c);
	abc.y = 2 * v_dot(view->ray.dir, dist);
	abc.z = v_dot(dist, dist) - (world.sp[world.sp_cnt].r *
			world.sp[world.sp_cnt].r);
	dt0t1.x = abc.y * abc.y - 4 * abc.x * abc.z;
	if (dt0t1.x < 0)
		return (false);
	dt0t1.y = (-abc.y + sqrtf(dt0t1.x)) / (2 * abc.x);
	dt0t1.z = (-abc.y - sqrtf(dt0t1.x)) / (2 * abc.x);
	if (dt0t1.y >= 0.1 && dt0t1.z >= 0.1)
		(dt0t1.y > dt0t1.z) ? (dt0t1.y = dt0t1.z) : (0);
	else
		(dt0t1.y < 0.1) ? (dt0t1.y = dt0t1.z) : (0);
	if (dt0t1.y > 0.1f && dt0t1.y < view->t)
	{
		ft_hit(world, view, dt0t1);
		return (true);
	}
	return (false);
}
