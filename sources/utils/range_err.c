/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:54:50 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/08 16:55:17 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	range_err(float f, float i, float j)
{
	if (f < i || f > j)
		return (true);
	return (false);
}
