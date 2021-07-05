/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_math1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:44:36 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 21:16:04 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	v_dot(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vect	v_cross(t_vect v1, t_vect v2)
{
	t_vect v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}
