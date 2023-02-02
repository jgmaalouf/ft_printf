# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 10:12:57 by jmaalouf          #+#    #+#              #
#    Updated: 2023/02/02 13:03:42 by jmaalouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils/ft_hex_conversion.c ft_printf_utils/ft_libft_mod.c \
		ft_printf_utils/ft_num_output.c ft_printf_utils/ft_printf_ntoa.c \
		ft_printf_format/ft_format_1.c ft_printf_format/ft_format_2.c \
		ft_printf_format/ft_format_check.c

SRC_OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${SRC_OBJ}
	cp libft.a $(NAME)
	ar rcs $@ $^

%.o: %.c
	${CC} ${FLAGS} -c $^ -o $@

clean:
	rm -f *.o ft_printf_*/*.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
