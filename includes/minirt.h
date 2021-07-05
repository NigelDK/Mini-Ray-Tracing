/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:30:11 by nde-koni          #+#    #+#             */
/*   Updated: 2021/03/23 12:57:22 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <float.h>
# include "../mlx/mlx.h"
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct	s_vect
{
	float	x;
	float	y;
	float	z;
}				t_vect;

typedef struct	s_sp
{
	t_vect	c;
	float	r;
	t_vect	col;
}				t_sp;

typedef struct	s_pl
{
	t_vect	c;
	t_vect	orient;
	t_vect	col;
}				t_pl;

typedef struct	s_tr
{
	t_vect	c0;
	t_vect	c1;
	t_vect	c2;
	t_vect	col;
}				t_tr;

typedef struct	s_cy
{
	t_vect	c;
	t_vect	orient;
	float	d;
	float	h;
	t_vect	col;
}				t_cy;

typedef struct	s_sq
{
	t_vect	c;
	t_vect	orient;
	float	ss;
	t_vect	col;
}				t_sq;

typedef struct	s_ray
{
	t_vect	ori;
	t_vect	dir;
}				t_ray;

typedef struct	s_cam
{
	t_vect	vp;
	t_vect	dir;
	int		w;
	int		h;
	int		fov;
}				t_cam;

typedef struct	s_ali
{
	float	ratio;
	t_vect	col;
}				t_ali;

typedef struct	s_li
{
	t_vect	ori;
	float	ratio;
	t_vect	col;
}				t_li;

typedef struct	s_world
{
	t_sp	*sp;
	t_pl	*pl;
	t_tr	*tr;
	t_cy	*cy;
	t_sq	*sq;
	int		sp_cnt;
	int		sp_loc;
	int		pl_cnt;
	int		pl_loc;
	int		tr_cnt;
	int		tr_loc;
	int		cy_cnt;
	int		cy_loc;
	int		sq_cnt;
	int		sq_loc;
	int		width;
	int		height;
	t_vect	col;
	t_ali	ali;
}				t_world;

typedef struct	s_view
{
	t_ray	ray;
	float	t;
	t_vect	colobj;
	int		obj;
	int		obj_nr;
	float	n;
}				t_view;

typedef struct	s_data
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	unsigned char	*bmp_img;
	unsigned char	header[54];
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_world			world;
	t_view			view;
	t_cam			*cam;
	t_li			*li;
	int				res_cnt;
	int				cam_cnt;
	int				cam_loc;
	int				ali_cnt;
	int				li_cnt;
	int				li_loc;
	char			**line;
	char			**read_line;
}				t_data;

typedef struct	s_tabs
{
	char	**tab_a;
	char	**tab_b;
	char	**tab_c;
	char	**tab_d;
	char	**tab_e;
}				t_tabs;

int				get_next_line(int fd, char **line, t_data *img);
size_t			gnl_strlen(const char *s);
char			*gnl_strjoin(char const *s1, char const *s2);

t_vect			v_init(float x, float y, float z);
t_vect			v_add(t_vect v1, t_vect v2);
t_vect			v_sub(t_vect v1, t_vect v2);
t_vect			v_scale(float c, t_vect v);
t_vect			v_unit(t_vect v);
float			v_dot(t_vect v1, t_vect v2);
t_vect			v_cross(t_vect v1, t_vect v2);
t_ray			cam_ray(int x, int y, t_cam cam);

void			raytracing(t_data *img);
bool			hit_obj(t_world world, t_view *view);
bool			hit_sp(t_world world, t_view *view);
bool			hit_pl(t_world world, t_view *view);
bool			hit_tr(t_world world, t_view *view);
bool			hit_cy(t_world world, t_view *view);
bool			hit_cydisk(t_world world, t_view *view);
bool			hit_cydisk2(t_world world, t_view *view);
bool			hit_sq(t_world world, t_view *view);

t_vect			get_light(t_world world, t_view view, t_li *li, int li_cnt);
t_vect			get_light_sp(t_world world, t_view view, t_li li);
t_vect			get_light_pl(t_world world, t_view view, t_li li);
t_vect			get_light_tr(t_world world, t_view view, t_li li);
t_vect			get_light_cy(t_world world, t_view view, t_li li);
t_vect			get_light_dsk(t_world world, t_view view, t_li li);
t_vect			get_light_sq(t_world world, t_view view, t_li li);
t_vect			get_ambi_light(t_world world);

void			parse(t_data *img, char *rt);
void			get_identifier(t_data *img, char **s);
void			parse_res(char *line, t_data *img);
void			parse_ali(char *line, t_data *img);
void			parse_cam(char *line, t_data *img);
void			parse_li(char *line, t_data *img);
void			parse_sp(char *line, t_data *img);
void			parse_pl(char *line, t_data *img);
void			parse_sq(char *line, t_data *img);
void			parse_tr(char *line, t_data *img);
void			parse_cy(char *line, t_data *img);
float			ft_atof(char *s);

int				save_tobmp(t_data *img);

void			ft_free(char **s, int i, char *msg);
void			ft_free_all(t_data *img, int i);
void			ft_free_tab(t_data *img, char ***tab, int j, char *s);
void			ft_free_tabb(char ***tab);
void			ft_free_specific(t_data *img, int i);
void			ft_free_end(t_data *img);
bool			comma_err(char *s, int k);
bool			range_err(float f, float i, float j);
bool			dot_err(char *s, int i);
bool			tab_err(char **tab, int i);
void			char_err(t_data *img, char *s, char *msg);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_rotation(t_vect *vect, t_vect angle);

#endif
