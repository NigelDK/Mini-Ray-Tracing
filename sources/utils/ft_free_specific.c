/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_specific.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:53:00 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/20 08:14:12 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	ft_free_specific(t_data *img, int i)
{
	if (img->cam_cnt)
		free(img->cam);
	if (img->li_cnt)
		free(img->li);
	if (img->world.sp_cnt)
		free(img->world.sp);
	if (img->world.pl_cnt)
		free(img->world.pl);
	if (img->world.sq_cnt)
		free(img->world.sq);
	if (img->world.tr_cnt)
		free(img->world.tr);
	if (img->world.cy_cnt)
		free(img->world.cy);
	if (i == 1)
		printf("Error\nInvalid amount of element R or c\n");
	exit(0);
}
