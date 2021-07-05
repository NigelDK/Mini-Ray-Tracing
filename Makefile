NAME = miniRT

SRC =	sources/raytracing/raytracing.c \
		sources/raytracing/cam_ray.c \
		sources/raytracing/hit_obj.c \
		sources/raytracing/hit_sp.c \
		sources/raytracing/hit_pl.c \
		sources/raytracing/hit_tr.c \
		sources/raytracing/hit_cy.c \
		sources/raytracing/hit_cydisk.c \
		sources/raytracing/hit_cydisk2.c \
		sources/raytracing/hit_sq.c \
		sources/raytracing/get_light.c \
		sources/raytracing/get_light_sp.c \
		sources/raytracing/get_light_pl.c \
		sources/raytracing/get_light_tr.c \
		sources/raytracing/get_light_cy.c \
		sources/raytracing/get_light_sq.c \
		sources/raytracing/v_math.c \
		sources/raytracing/v_math1.c \
		sources/parse/parse.c \
		sources/parse/get_identifier.c \
		sources/parse/parse_res.c \
		sources/parse/parse_ali.c \
		sources/parse/parse_cam.c \
		sources/parse/parse_li.c \
		sources/parse/parse_sp.c \
		sources/parse/parse_pl.c \
		sources/parse/parse_sq.c \
		sources/parse/parse_tr.c \
		sources/parse/parse_cy.c \
		sources/bmp/bmp.c \
		sources/utils/ft_atof.c \
		sources/utils/ft_free.c \
		sources/utils/ft_free_all.c \
		sources/utils/ft_free_tab.c \
		sources/utils/ft_free_tabb.c \
		sources/utils/ft_free_end.c \
		sources/utils/ft_free_specific.c \
		sources/utils/comma_err.c \
		sources/utils/range_err.c \
		sources/utils/dot_err.c \
		sources/utils/tab_err.c \
		sources/utils/char_err.c \
		sources/utils/my_mlx_pixel_put.c \
		sources/utils/ft_rotation.c \
		sources/utils/get_next_line.c \
		sources/utils/get_next_line_utils.c \
		sources/main.c \

HEADER = includes/minirt.h

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -O2 -DDONT_USE_VOL -Wall -Wextra -Werror -g

RM = rm -rf


all:	$(NAME)

$(NAME):	$(OBJ)
	@cd mlx && ./configure && cd ..
	@cd sources/libft && make && cd ../..
	@echo "Making miniRT"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(HEADER) sources/libft/libft.a -I/usr/include -Imlx -Lmlx -lmlx -lXext -lX11 -lm

%.o:	%.c
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files"
	@cd sources/libft && make clean && cd ../..
	@cd mlx && ./configure clean && cd ..
	@$(RM) $(OBJ)

fclean:
	@echo "Removing object files"
	@$(RM) $(NAME) $(OBJ_BONUS) $(OBJ)
	@cd sources/libft && make fclean && cd ../..
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bclean bonus
