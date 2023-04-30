NAME = get_next_line.a

SRC =	get_next_line.c			\
		get_next_line_utils.c	\

OBJT = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --quiet

all: $(NAME)

$(NAME): $(OBJT)
	ar rcs $(NAME) $(OBJT)
	gcc $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJT)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
