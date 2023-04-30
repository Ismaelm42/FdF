# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 12:09:39 by imoro-sa          #+#    #+#              #
#    Updated: 2023/01/23 11:27:47 by imoro-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ../libft/libft.a

SRC =	ft_printf.c				\
		ft_call.c				\
		ft_char.c				\
		ft_string.c				\
		ft_pointer.c			\
		ft_decimal.c 			\
		ft_integer.c			\
		ft_unsigned.c			\
		ft_lower_case_hex.c		\
		ft_cap_hex.c			\

OBJT = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

MAKEFLAGS += --quiet

all: $(NAME)

$(NAME): $(OBJT) $(LIBFT)
	$(CC) $(CFLAGS) -c $(SRC)
	$(AR) $(NAME) $(LIBFT) $(OBJT)

$(LIBFT):
	make -C ../libft/

clean:
	$(RM) $(OBJT)
	make clean -C ../libft/

fclean: clean
	$(RM) $(NAME)
	make fclean -C ../libft/

re: fclean all

.PHONY: all clean fclean re
