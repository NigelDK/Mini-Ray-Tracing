/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:45:40 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/22 14:08:03 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ft_error(t_data *img)
{
	printf("Error\nInvalid identifier\n");
	ft_free_all(img, 1);
}

void		get_identifier(t_data *img, char **s)
{
	int	i;

	i = 0;
	while (s[0][i] == ' ')
		i++;
	if (s[0][i] == 'R' && s[0][i + 1] == ' ')
		parse_res(s[0] + i + 1, img);
	else if (s[0][i] == 'A' && s[0][i + 1] == ' ')
		parse_ali(s[0] + i + 1, img);
	else if (s[0][i] == 'c' && s[0][i + 1] != 'y' && s[0][i + 1] == ' ')
		parse_cam(s[0] + i + 1, img);
	else if (s[0][i] == 'l' && s[0][i + 1] == ' ')
		parse_li(s[0] + i + 1, img);
	else if (s[0][i] == 's' && s[0][i + 1] == 'p' && s[0][i + 2] == ' ')
		parse_sp(s[0] + i + 2, img);
	else if (s[0][i] == 'p' && s[0][i + 1] == 'l' && s[0][i + 2] == ' ')
		parse_pl(s[0] + i + 2, img);
	else if (s[0][i] == 's' && s[0][i + 1] == 'q' && s[0][i + 2] == ' ')
		parse_sq(s[0] + i + 2, img);
	else if (s[0][i] == 'c' && s[0][i + 1] == 'y' && s[0][i + 2] == ' ')
		parse_cy(s[0] + i + 2, img);
	else if (s[0][i] == 't' && s[0][i + 1] == 'r' && s[0][i + 2] == ' ')
		parse_tr(s[0] + i + 2, img);
	else
		ft_error(img);
}
