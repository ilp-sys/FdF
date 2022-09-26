# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 23:07:10 by jiwahn            #+#    #+#              #
#    Updated: 2022/09/26 18:05:56 by jiwahn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

MLX = mlx/
MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit 

INC = includes/

LIBFT_DIR = libft/
LIBFT_LIB = libft.a

SRC_DIR = srcs/
SRCS = main.c parsing.c project.c render.c \
	   mouse_handler.c mlx_utils.c fdf_utils.c \
	   get_next_line.c

all :
	$(MAKE) -C $(LIBFT_DIR) bonus 
	$(CC) $(CFLAGS) -L$(MLX) $(MLX_FLAGS) $(LIBFT_DIR)$(LIBFT_LIB) $(addprefix $(SRC_DIR), $(SRCS)) -o $(NAME)

fclean : 
	rm -rf $(wildcard *.o)
	rm -rf $(NAME)

.PHONY : fclean all
