NAME = Libft.a

LIBFT = ./libft/libft.a

FT_PRINTF = ./ft_printf/ft_printf.a

GET_NEXT_LINE = ./get_next_line/get_next_line.a

AR = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --quiet

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE)
		$(AR) $(NAME) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE)

$(LIBFT):
		make -C ./libft

$(FT_PRINTF):
		make -C ./ft_printf

$(GET_NEXT_LINE):
		make -C ./get_next_line

clean:
		make clean -C ./libft
		make clean -C ./ft_printf
		make clean -C ./get_next_line

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIBFT)
		$(RM) $(FT_PRINTF)
		$(RM) $(GET_NEXT_LINE)

re: fclean all

.PHONY: all clean fclean re
