# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 12:47:47 by angalsty          #+#    #+#              #
#    Updated: 2023/03/08 12:57:52 by angalsty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c check.c check_map.c initialize.c error.c draw_map.c moves.c \
       path.c

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft

MLX42_PATH = ./MLX42

INC		= -I $(MLX42_PATH)/include -I $(LIBFT_PATH)

GLFW_FLAGS = -lglfw -L /Users/angalsty/.brew/opt/glfw/lib

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -I.

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

all: ${NAME}
	

${NAME}:  ${OBJS}
		make -C $(LIBFT_PATH)
		make -C $(MLX42_PATH)
		@gcc -c $(SRCS) $(CFLAGS) $(INC)
		${CC} ${CFLAGS} ${OBJS} $(INC) $(LIBFT_PATH)/libft.a ${MLX42_PATH}/libmlx42.a ${GLFW_FLAGS} -o ${NAME}

clean:
		make -C $(LIBFT_PATH) clean
		make -C $(MLX42_PATH) clean
		${RM} ${OBJS}


fclean:		clean
		make -C $(LIBFT_PATH) fclean
		make -C $(MLX42_PATH) fclean
		${RM} ${NAME}

re: fclean all
	make -C $(LIBFT_PATH)
	make -C $(MLX42_PATH)

.PHONY: all clean fclean re
