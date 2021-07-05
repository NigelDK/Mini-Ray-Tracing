/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:10:08 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/19 16:44:25 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int		bmp_error(t_data *img, int fd)
{
	free(img->bmp_img);
	img->bmp_img = NULL;
	if (fd != -1)
		close(fd);
	exit(0);
}

static void		fill_img(t_data *img, int x, int y)
{
	img->view.t = 400000.0f;
	img->view.colobj = img->world.col;
	img->view.ray = cam_ray(x, y, img->cam[0]);
	if (hit_obj(img->world, &img->view))
		img->view.colobj = get_light(img->world, img->view, img->li,
			img->li_cnt);
	img->bmp_img[(x + y * img->world.width) * 3 + 2] =
		(unsigned char)img->view.colobj.x;
	img->bmp_img[(x + y * img->world.width) * 3 + 1] =
		(unsigned char)img->view.colobj.y;
	img->bmp_img[(x + y * img->world.width) * 3 + 0] =
		(unsigned char)img->view.colobj.z;
}

static int		create_img(t_data *img)
{
	int	x;
	int	y;

	img->cam[0].w = img->world.width;
	img->cam[0].h = img->world.height;
	if (!(img->bmp_img = malloc(sizeof(unsigned char) *
			(img->world.width * img->world.height * 3))))
		exit(0);
	y = 0;
	while (y < img->world.height)
	{
		x = 0;
		while (x < img->world.width)
		{
			fill_img(img, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

static void		ft_header(t_data *img, int stride)
{
	int				file_size;

	file_size = 54 + (stride * img->world.height);
	ft_bzero(img->header, 54);
	img->header[0] = 'B';
	img->header[1] = 'M';
	img->header[2] = file_size;
	img->header[3] = file_size >> 8;
	img->header[4] = file_size >> 16;
	img->header[5] = file_size >> 24;
	img->header[10] = 54;
	img->header[14] = 40;
	img->header[18] = img->world.width;
	img->header[19] = img->world.width >> 8;
	img->header[20] = img->world.width >> 16;
	img->header[21] = img->world.width >> 24;
	img->header[22] = img->world.height;
	img->header[23] = img->world.height >> 8;
	img->header[24] = img->world.height >> 16;
	img->header[25] = img->world.height >> 24;
	img->header[26] = 1;
	img->header[28] = 3 * 8;
}

int				save_tobmp(t_data *img)
{
	unsigned char	pad[3];
	int				i;
	int				row_b;
	int				pad_size;
	int				fd;

	create_img(img);
	row_b = img->world.width * 3;
	ft_bzero(pad, 3);
	pad_size = (4 - row_b % 4) % 4;
	if ((fd = open("scene.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
		bmp_error(img, -1);
	ft_header(img, row_b + pad_size);
	(write(fd, img->header, 54) == -1) ? (bmp_error(img, fd)) : (0);
	i = img->world.height;
	while (i-- > 0)
	{
		if (write(fd, img->bmp_img + (i * row_b), row_b) == -1)
			bmp_error(img, fd);
		(write(fd, pad, pad_size) == -1) ? (bmp_error(img, fd)) : (0);
	}
	close(fd);
	free(img->bmp_img);
	ft_free_end(img);
	return (0);
}
