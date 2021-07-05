/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:16:49 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/23 10:42:02 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static bool	check_save(char *s)
{
	int		i;
	char	*save;

	save = "--save\0";
	i = 0;
	while (s[i] && save[i] && s[i] == save[i])
		i++;
	if ((s[i] != save[i]) || (s[i] && !save[i]) || (!s[1] && save[i]))
		return (false);
	return (true);
}

int			key_hook(int keycode, t_data *img)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		ft_free_end(img);
		exit(0);
	}
	if (keycode == 65436)
		raytracing(img);
	return (0);
}

int			close_win(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	ft_free_end(img);
	exit(0);
	return (0);
}

int			rebuild_img(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	img;
	int		width;
	int		height;

	if (argc < 2 || argc > 3 || (argc == 3 && !check_save(argv[2])))
		return (0);
	parse(&img, argv[1]);
	(img.res_cnt != 1 || img.cam_cnt == 0) ? (ft_free_specific(&img, 1)) : (0);
	img.world.col = v_init(0, 0, 0);
	if (argc == 3 && check_save(argv[2]))
		return (save_tobmp(&img));
	img.mlx = mlx_init();
	mlx_get_screen_size(img.mlx, &width, &height);
	(img.world.width > width) ? (img.world.width = width) : (0);
	(img.world.height > height) ? (img.world.height = height) : (0);
	img.mlx_win = mlx_new_window(img.mlx, img.world.width,
			img.world.height, "miniRT");
	img.img = mlx_new_image(img.mlx, img.world.width, img.world.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	raytracing(&img);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_hook(img.mlx_win, 17, (1L << 17), close_win, &img);
	mlx_expose_hook(img.mlx_win, rebuild_img, &img);
	mlx_loop(img.mlx);
}
