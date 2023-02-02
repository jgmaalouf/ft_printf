# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 10:12:57 by jmaalouf          #+#    #+#              #
#    Updated: 2022/08/04 15:09:17 by jmaalouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils/ft_hex_conversion.c ft_printf_utils/ft_libft_mod.c \
		ft_printf_utils/ft_num_output.c ft_printf_utils/ft_printf_ntoa.c \
		ft_printf_format/ft_format_1.c ft_printf_format/ft_format_2.c \
		ft_printf_format/ft_format_check.c

BONUS = ft_printf_bonus.c ft_printf_utils_bonus/ft_hex_conversion_bonus.c \
		ft_printf_utils_bonus/ft_libft_mod_bonus.c ft_printf_utils_bonus/ft_num_output_bonus.c \
		ft_printf_utils_bonus/ft_printf_ntoa_bonus.c ft_printf_format_bonus/ft_format_1_bonus.c \
		ft_printf_format_bonus/ft_format_2_bonus.c ft_printf_format_bonus/ft_format_check_bonus.c

SRC_OBJ = ${SRC:.c=.o}

B_OBJ = ${BONUS:.c=.o}

all: ${NAME}

${NAME}: ${SRC_OBJ}
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $@ $^

%.o: %.c
	${CC} ${FLAGS} -c $^ -o $@

bonus: ${B_OBJ}
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs libftprintf.a $^

clean:
	${MAKE} clean -C ./libft
	rm -f *.o ft_printf_*/*.o

fclean: clean
	${MAKE} fclean -C ./libft
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
