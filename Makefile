# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 11:31:34 by imoro-sa          #+#    #+#              #
#    Updated: 2023/05/12 18:14:26 by imoro-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

ifeq ($(shell uname), Darwin)
	INCFLAGS =  -DEBUG=1 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
else
	INCFLAGS = -ldl -DEBUG=1 -Iinclude -lglfw -L"usr/lib/x86_64-linux-gnu/"
endif

SRC =	main.c					\
		fdf_parse.c				\
		fdf_parse_utils.c		\
		fdf_draw.c				\
		fdf_viewpoint.c		\
		fdf_viewpoint_utils.c	\
		fdf_utils.c				\
		fdf_hooks.c				\
		fdf_hooks_utils.c		\

OBJT = $(SRC:.c=.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

MLX42_DIR = ./MLX42

MLX42 = $(MLX42_DIR)/libmlx42.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

MAKEFLAGS += --quiet

all: $(LIBFT) $(MLX42) $(NAME)
	$(MAKE) clean

$(NAME): $(OBJT)
		$(CC) $(CFLAGS) $(SRC) -o $(NAME) -lm $(LIBFT) $(MLX42) $(INCFLAGS)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(MLX42):
		$(MAKE) -C $(MLX42_DIR)

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		$(MAKE) clean -C $(MLX42_DIR)
		$(RM) $(OBJT)

fclean: clean
		$(MAKE) fclean -C $(LIBFT_DIR)
		$(MAKE) fclean -C $(MLX42_DIR)
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
