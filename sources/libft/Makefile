# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/31 14:25:11 by nde-koni          #+#    #+#              #
#    Updated: 2021/03/19 15:11:13 by nde-koni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \

SRC_BONUS = ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstlast.c \
			ft_lstnew.c \
			ft_lstsize.c \

HEADER = libft.h

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

AR = ar rc


all:	$(NAME)

$(NAME):	$(OBJ)
	@echo "Making library"
	@$(AR) $(NAME) $(OBJ) $(HEADER)

%.o:	%.c
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -c $< -o $@


bonus: $(OBJ_BONUS)
	@echo "Adding bonus part to library" 
	@$(AR) $(NAME) $(OBJ_BONUS)

clean:
	@echo "Removing object files"
	@$(RM) $(OBJ)

fclean:
	@echo "Removing library and all object files"
	@$(RM) $(NAME) $(OBJ_BONUS) $(OBJ)

bclean:
	@echo "Removing bonus object files"
	@$(RM) $(OBJ_BONUS)

re: fclean all

.PHONY: all clean fclean re bclean bonus
