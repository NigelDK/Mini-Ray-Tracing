/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_math.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:11:02 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 21:15:21 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vect	v_init(float x, float y, float z)
{
	t_vect	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vect	v_add(t_vect v1, t_vect v2)
{
	t_vect result;

	result = v_init(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	return (result);
}

t_vect	v_sub(t_vect v1, t_vect v2)
{
	t_vect result;

	result = v_init(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	return (result);
}

t_vect	v_scale(float c, t_vect v)
{
	t_vect result;

	result = v_init(v.x * c, v.y * c, v.z * c);
	return (result);
}

t_vect	v_unit(t_vect v)
{
	float	k;

	k = 1.0 / sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (v_scale(k, v));
}
