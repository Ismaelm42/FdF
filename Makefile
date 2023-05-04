NAME = fdf

ifeq ($(shell uname), Darwin)
	CFLAGS = -Wall -Werror -Wextra -DEBUG=1 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
else
	CFLAGS = -Wall -Werror -ldl -Wextra -DEBUG=1 -Iinclude -lglfw -L"usr/lib/x86_64-linux-gnu/"
endif

SRC =	main.c				\
		fdf_map_init.c		\
		fdf_utils.c			\

OBJT = $(SRC:.c=.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

MLX42_DIR = ./MLX42

MLX42 = $(MLX42_DIR)/libmlx42.a

CC = gcc

RM = rm -f

MAKEFLAGS += --quiet

all: $(LIBFT) $(MLX42) $(NAME)

$(NAME): $(OBJT)
		$(CC) $(SRC) -o $(NAME) $(LIBFT) $(MLX42) $(CFLAGS)

$(LIBFT):
		make -C $(LIBFT_DIR)

$(MLX42):
		make -C $(MLX42_DIR)

clean:
		make clean -C $(LIBFT_DIR)
		make clean -C $(MLX42_DIR)
		$(RM) $(OBJT)

fclean: clean
		make fclean -C $(LIBFT_DIR)
		make clean -C $(MLX42_DIR)
		$(RM) $(NAME)

re: fclean all
	$(MAKE) clean

.PHONY: all clean fclean re
