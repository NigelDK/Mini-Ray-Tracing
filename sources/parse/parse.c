/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:56:22 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/22 09:36:12 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	init_counter(t_data *img, int *i)
{
	img->res_cnt = 0;
	img->cam_cnt = 0;
	img->ali_cnt = 0;
	img->li_cnt = 0;
	img->world.sp_cnt = 0;
	img->world.pl_cnt = 0;
	img->world.sq_cnt = 0;
	img->world.cy_cnt = 0;
	img->world.tr_cnt = 0;
	img->cam_loc = 0;
	img->li_loc = 0;
	img->world.sp_loc = 0;
	img->world.pl_loc = 0;
	img->world.sq_loc = 0;
	img->world.cy_loc = 0;
	img->world.tr_loc = 0;
	i[0] = 1;
}

void		init_ali(t_data *img)
{
	img->world.ali.ratio = 0;
	img->world.ali.col = v_init(0, 0, 0);
}

static void	obj_counter(t_data *img, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'R')
		img->res_cnt++;
	else if (line[i] == 'c' && line[i + 1] != 'y')
		img->cam_cnt++;
	else if (line[i] == 'l')
		img->li_cnt++;
	else if (line[i] == 's' && line[i + 1] == 'p')
		img->world.sp_cnt++;
	else if (line[i] == 'p' && line[i + 1] == 'l')
		img->world.pl_cnt++;
	else if (line[i] == 's' && line[i + 1] == 'q')
		img->world.sq_cnt++;
	else if (line[i] == 'c' && line[i + 1] == 'y')
		img->world.cy_cnt++;
	else if (line[i] == 't' && line[i + 1] == 'r')
		img->world.tr_cnt++;
	if (img->ali_cnt == 0)
		init_ali(img);
}

static void	malloc_counter(t_data *img)
{
	if (img->cam_cnt)
		if (!(img->cam = malloc(sizeof(t_cam) * img->cam_cnt)))
			ft_free_specific(img, 0);
	if (img->li_cnt)
		if (!(img->li = malloc(sizeof(t_li) * img->li_cnt)))
			ft_free_specific(img, 0);
	if (img->world.sp_cnt)
		if (!(img->world.sp = malloc(sizeof(t_sp) * img->world.sp_cnt)))
			ft_free_specific(img, 0);
	if (img->world.pl_cnt)
		if (!(img->world.pl = malloc(sizeof(t_pl) * img->world.pl_cnt)))
			ft_free_specific(img, 0);
	if (img->world.sq_cnt)
		if (!(img->world.sq = malloc(sizeof(t_sq) * img->world.sq_cnt)))
			ft_free_specific(img, 0);
	if (img->world.tr_cnt)
		if (!(img->world.tr = malloc(sizeof(t_tr) * img->world.tr_cnt)))
			ft_free_specific(img, 0);
	if (img->world.cy_cnt)
		if (!(img->world.cy = malloc(sizeof(t_cy) * img->world.cy_cnt)))
			ft_free_specific(img, 0);
}

void		parse(t_data *img, char *rt)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(rt, O_RDONLY);
	(fd == -1) ? (exit(0)) : (0);
	init_counter(img, &i);
	while (i == 1)
	{
		i = get_next_line(fd, &line, img);
		(line[0] != '\0') ? (obj_counter(img, line)) : (0);
		(line) ? (free(line)) : (0);
	}
	close(fd);
	malloc_counter(img);
	fd = open(rt, O_RDONLY);
	i = 1;
	while (i == 1)
	{
		i = get_next_line(fd, &line, img);
		img->line = &line;
		(line[0] != '\0') ? (get_identifier(img, &line)) : (0);
		(line) ? (free(line)) : (0);
	}
	close(fd);
}
