/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:59:58 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/23 13:01:40 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	stray_min(t_data *img, char *s, char *msg)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (s[i] == '-')
	{
		printf("Error\nEncountered invalid input at %s\n", msg);
		ft_free_all(img, 1);
	}
}

static void	num_min_num(t_data *img, char *s, char *msg)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) && s[i + 1] == '-' && ft_isdigit(s[i + 2]))
		{
			printf("Error\nEncountered invalid input at %s\n", msg);
			ft_free_all(img, 1);
		}
		i++;
	}
}

static void	find_needle(t_data *img, char *s, char *msg, char *err)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = ft_strlen(err);
	while (s[i])
	{
		j = 0;
		while (s[i] && err[j] && s[i] == err[j])
		{
			i++;
			j++;
		}
		if (j == k)
		{
			printf("Error\nEncountered invalid input at %s\n", msg);
			ft_free_all(img, 1);
		}
		(s[i]) ? (i++) : (0);
	}
}

static void	specific_err(t_data *img, char *s, char *msg)
{
	num_min_num(img, s, msg);
	stray_min(img, s, msg);
	find_needle(img, s, msg, " - ");
	find_needle(img, s, msg, "- ");
	find_needle(img, s, msg, "-,");
	find_needle(img, s, msg, ",-,");
	find_needle(img, s, msg, ",- ");
	find_needle(img, s, msg, "--");
	find_needle(img, s, msg, ".-");
	find_needle(img, s, msg, ". ");
	find_needle(img, s, msg, " . ");
	find_needle(img, s, msg, " .");
	find_needle(img, s, msg, ",.");
}

void		char_err(t_data *img, char *s, char *msg)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	str = "0123456789,.- \0";
	while (s[i])
	{
		j = 0;
		k = 0;
		while (str[j])
		{
			if (s[i] == str[j])
				k = 1;
			j++;
		}
		if (k == 0)
		{
			printf("Error\nEncountered invalid input at %s\n", msg);
			ft_free_all(img, 1);
		}
		i++;
	}
	specific_err(img, s, msg);
}
