/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:45:47 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 20:41:22 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool		get_shadow_rest(t_world world, t_view view)
{
	int	i;

	i = world.cy_cnt;
	while (--world.cy_cnt >= 0)
		if (hit_cy(world, &view))
			return (true);
	world.cy_cnt = i;
	while (--world.cy_cnt >= 0)
		if (hit_cydisk(world, &view))
			return (true);
	world.cy_cnt = i;
	while (--world.cy_cnt >= 0)
		if (hit_cydisk2(world, &view))
			return (true);
	while (--world.sq_cnt >= 0)
		if (hit_sq(world, &view))
			return (true);
	return (false);
}

static bool		get_shadow(t_world world, t_view view, t_li li)
{
	view.ray.ori = v_add(view.ray.ori, v_scale(view.t, view.ray.dir));
	view.ray.dir = v_sub(li.ori, view.ray.ori);
	view.t = sqrtf(v_dot(view.ray.dir, view.ray.dir));
	view.ray.dir = v_unit(view.ray.dir);
	while (--world.sp_cnt >= 0)
		if (hit_sp(world, &view))
			return (true);
	while (--world.pl_cnt >= 0)
		if (hit_pl(world, &view))
			return (true);
	while (--world.tr_cnt >= 0)
		if (hit_tr(world, &view))
			return (true);
	return (get_shadow_rest(world, view));
}

static t_vect	get_light_obj(t_world world, t_view view, t_li li)
{
	t_vect	colour;

	colour = world.col;
	if (get_shadow(world, view, li))
		return (colour);
	if (view.obj == 1)
		colour = get_light_sp(world, view, li);
	else if (view.obj == 2)
		colour = get_light_pl(world, view, li);
	else if (view.obj == 3)
		colour = get_light_tr(world, view, li);
	else if (view.obj == 4)
		colour = get_light_cy(world, view, li);
	else if (view.obj == 5)
		colour = get_light_dsk(world, view, li);
	else if (view.obj == 6)
		colour = get_light_sq(world, view, li);
	return (colour);
}

t_vect			get_light(t_world world, t_view view, t_li *li, int li_cnt)
{
	t_vect	col_li;
	t_vect	col_ali;
	int		i;

	i = 0;
	col_li = v_init(0, 0, 0);
	while (i < li_cnt)
		col_li = v_add(col_li, get_light_obj(world, view, li[i++]));
	col_li.x = view.colobj.x * col_li.x;
	col_li.y = view.colobj.y * col_li.y;
	col_li.z = view.colobj.z * col_li.z;
	col_ali = get_ambi_light(world);
	col_ali.x = view.colobj.x * col_ali.x;
	col_ali.y = view.colobj.y * col_ali.y;
	col_ali.z = view.colobj.z * col_ali.z;
	view.colobj = v_add(col_li, col_ali);
	(view.colobj.x > 255) ? (view.colobj.x = 255) : (0);
	(view.colobj.y > 255) ? (view.colobj.y = 255) : (0);
	(view.colobj.z > 255) ? (view.colobj.z = 255) : (0);
	return (view.colobj);
}
