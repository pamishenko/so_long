# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 15:07:50 by ttanja            #+#    #+#              #
#    Updated: 2021/10/19 08:49:38 by ttanja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

LIBFT_PATH		=	./libft/
LIBFT_LIB		=	$(LIBFT_PATH)libft.a

MLX_PATH		=	./mlx/
MLX_LIB			=	$(MLX_PATH)libmlx.dylib

HEADER_FOLDER	=	./includes/

HEADER_FILES	=	\
					${HEADER_FOLDER}so_long.h \
					${HEADER_FOLDER}structures.h \
					${HEADER_FOLDER}constants.h

SRC				=	\
					./src/ft_init_map.c \
					./src/ft_map_checker.c \
					./src/ft_map_checker2.c \
					./src/ft_map_elements_util.c \
					./src/ft_move.c \
					./src/ft_parser_map.c \
					./src/so_long.c 

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

OBJ				= ${SRC:.c=.o}

%.o: %.c ${HEADER_FILES}
	$(CC) $(CFLAGS) -I $(HEADER_FOLDER) -Imlx -Ift -c $< -o $@ 


all:		$(NAME) $(LIBFT_LIB)

$(NAME): $(OBJ) ${HEADER_FILES}
	make -C $(MLX_PATH)
	make -C $(LIBFT_PATH)
	cp $(MLX_LIB) ./
	cp $(LIBFT_LIB) ./
	$(CC) $(CFLAGS) -I ${HEADER_FOLDER} $(OBJ) -L ./ -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			make -C ${LIBFT_PATH} clean
			make -C ${MLX_PATH} clean
			${RM} ${OBJ}

fclean:		clean
			rm -f libmlx.dylib
			rm -f libft.a
			${RM} ${NAME} ${LIBFT_LIB} $(MLX_LIB)

re:			fclean all

.PHONY:		all clean fclean re