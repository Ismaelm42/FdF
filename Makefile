NAME = fdf

SRC = check_map.c

OBJT = $(SRC:.c=.o)

LIBFT = ./libft/Libft.a

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --quiet

all: $(NAME)

$(NAME): $(LIBFT) $(OBJT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
		make -C ./libft
		ranlib $(LIBFT)

clean:
		make clean -C ./libft
		$(RM) $(OBJT)

fclean: clean
		make clean -C ./libft
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
