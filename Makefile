# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 23:07:10 by jiwahn            #+#    #+#              #
#    Updated: 2022/09/20 09:42:18 by jiwahn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror 

MLX = ../mlx
MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit 

INC = includes/

SRCS = main.c fdf_utils.c get_next_line.c parsing.c

