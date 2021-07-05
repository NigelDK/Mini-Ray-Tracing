/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_pl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:38:14 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/22 17:38:04 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	hit_pl(t_world world, t_view *view)
{
	t_vect	dist;
	float	angle;
	float	t0;

	dist = v_sub(world.pl[world.pl_cnt].c, view->ray.ori);
	angle = v_dot(view->ray.dir, world.pl[world.pl_cnt].orient);
	if (fabsf(angle) <= 0)
		return (false);
	t0 = v_dot(dist, world.pl[world.pl_cnt].orient) / angle;
	if (t0 >= 0.1f && t0 < view->t)
	{
		view->obj = 2;
		view->t = t0;
		view->colobj = world.pl[world.pl_cnt].col;
		view->obj_nr = world.pl_cnt;
		return (true);
	}
	return (false);
}
