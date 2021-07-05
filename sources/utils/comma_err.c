/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comma_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:30:47 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 22:20:11 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	comma_err(char *s, int k)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == ',')
			i++;
		j++;
	}
	if (i != k)
		return (true);
	return (false);
}
