/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:37:20 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/03 13:56:06 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	hit_obj(t_world world, t_view *view)
{
	int	i;

	view->obj = 0;
	i = world.cy_cnt;
	while (--world.sp_cnt >= 0)
		hit_sp(world, view);
	while (--world.pl_cnt >= 0)
		hit_pl(world, view);
	while (--world.tr_cnt >= 0)
		hit_tr(world, view);
	while (--world.cy_cnt >= 0)
		hit_cy(world, view);
	world.cy_cnt = i;
	while (--world.cy_cnt >= 0)
		hit_cydisk(world, view);
	world.cy_cnt = i;
	while (--world.cy_cnt >= 0)
		hit_cydisk2(world, view);
	while (--world.sq_cnt >= 0)
		hit_sq(world, view);
	if (view->obj == 0)
		return (false);
	return (true);
}
