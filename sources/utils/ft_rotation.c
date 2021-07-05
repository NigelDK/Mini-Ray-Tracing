/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:23:42 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/22 14:09:29 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void		rx(t_vect *vect, float x)
{
	t_vect	tmp;

	tmp.x = vect->x;
	tmp.y = vect->y * cos(x) - vect->z * sin(x);
	tmp.z = vect->y * sin(x) + vect->z * cos(x);
	*vect = tmp;
}

static void		ry(t_vect *vect, float y)
{
	t_vect	tmp;

	tmp.x = vect->x * cos(y) + vect->z * sin(y);
	tmp.y = vect->y;
	tmp.z = vect->x * -sin(y) + vect->z * cos(y);
	*vect = tmp;
}

static void		rz(t_vect *vect, float z)
{
	t_vect	tmp;

	tmp.x = vect->x * cos(z) - vect->y * sin(z);
	tmp.y = vect->x * sin(z) + vect->y * cos(z);
	tmp.z = vect->z;
	*vect = tmp;
}

void			ft_rotation(t_vect *vect, t_vect angle)
{
	rx(vect, angle.x);
	ry(vect, angle.y);
	rz(vect, angle.z);
}
