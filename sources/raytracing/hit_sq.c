/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:52:50 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 20:24:47 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	ft_hit(t_world world, t_view *view, float t0)
{
	if ((t0 >= 0.1f) && (t0 < view->t))
	{
		view->obj = 6;
		view->t = t0;
		view->colobj = world.sq[world.sq_cnt].col;
		view->obj_nr = world.sq_cnt;
		return (true);
	}
	return (false);
}

static bool	hit_trsq0(t_world world, t_view *view, t_vect *corner)
{
	t_vect	v1;
	t_vect	v2;
	t_vect	abc;
	float	t0;

	v1 = v_sub(corner[0], corner[2]);
	v2 = v_sub(corner[1], corner[2]);
	if (fabsf(v_dot(v1, v_cross(view->ray.dir, v2))) <= 0)
		return (false);
	abc.z = 1 / v_dot(v1, v_cross(view->ray.dir, v2));
	abc.x = v_dot(v_sub(view->ray.ori, corner[2]), v_cross(view->ray.dir, v2))
				* abc.z;
	abc.y = v_dot(view->ray.dir, v_cross(v_sub(view->ray.ori, corner[2]), v1))
				* abc.z;
	if (abc.y < 0 || abc.x + abc.y > 1 || abc.x < 0 || abc.x > 1)
		return (false);
	t0 = v_dot(v2, v_cross(v_sub(view->ray.ori, corner[2]), v1)) * abc.z;
	return (ft_hit(world, view, t0));
}

static bool	hit_trsq1(t_world world, t_view *view, t_vect *corner)
{
	t_vect	v1;
	t_vect	v2;
	t_vect	abc;
	float	t0;

	v1 = v_sub(corner[1], corner[3]);
	v2 = v_sub(corner[2], corner[3]);
	if (fabsf(v_dot(v1, v_cross(view->ray.dir, v2))) <= 0)
		return (false);
	abc.z = 1 / v_dot(v1, v_cross(view->ray.dir, v2));
	abc.x = v_dot(v_sub(view->ray.ori, corner[3]), v_cross(view->ray.dir, v2))
			* abc.z;
	abc.y = v_dot(view->ray.dir, v_cross(v_sub(view->ray.ori, corner[3]), v1))
			* abc.z;
	if (abc.y < 0 || abc.x + abc.y > 1 || abc.x < 0 || abc.x > 1)
		return (false);
	t0 = v_dot(v2, v_cross(v_sub(view->ray.ori, corner[3]), v1)) * abc.z;
	return (ft_hit(world, view, t0));
}

bool		hit_sq(t_world world, t_view *view)
{
	t_vect	corner[4];
	float	hss;

	hss = world.sq[world.sq_cnt].ss / 2;
	corner[0] = v_init(hss, hss, 0);
	corner[1] = v_init(-hss, hss, 0);
	corner[2] = v_init(hss, -hss, 0);
	corner[3] = v_init(-hss, -hss, 0);
	ft_rotation(&corner[0], world.sq[world.sq_cnt].orient);
	ft_rotation(&corner[1], world.sq[world.sq_cnt].orient);
	ft_rotation(&corner[2], world.sq[world.sq_cnt].orient);
	ft_rotation(&corner[3], world.sq[world.sq_cnt].orient);
	corner[0] = v_add(world.sq[world.sq_cnt].c, corner[0]);
	corner[1] = v_add(world.sq[world.sq_cnt].c, corner[1]);
	corner[2] = v_add(world.sq[world.sq_cnt].c, corner[2]);
	corner[3] = v_add(world.sq[world.sq_cnt].c, corner[3]);
	if (hit_trsq0(world, view, corner))
		return (true);
	else if (hit_trsq1(world, view, corner))
		return (true);
	return (false);
}
