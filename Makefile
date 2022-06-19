# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 10:12:57 by jmaalouf          #+#    #+#              #
#    Updated: 2022/06/08 15:01:20 by jmaalouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_uitoa.c ft_libft_mod.c \
		ft_itoa_printf.c ft_hex_conversion.c ft_hex_output.c \
		ft_format.c ft_format_check.c char_to_str.c

SRC_OBJ = ${SRC:.c=.o}


all: ${NAME}

${NAME}: ${SRC_OBJ}
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $@ $^

%.o: %.c
	${CC} ${FLAGS} -c $^ -o $@

clean:
	${MAKE} clean -C ./libft
	rm -f *.o

fclean: clean
	${MAKE} fclean -C ./libft
	rm -f ${NAME}

bonus: all

re: fclean all

.PHONY: all clean fclean re bonus
