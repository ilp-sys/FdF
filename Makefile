# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 23:07:10 by jiwahn            #+#    #+#              #
#    Updated: 2022/09/20 14:55:14 by jiwahn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror 

RM = rm
RMFLAGS = -rf

MLX = mlx/
MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit 

INC = includes/

LIBFT_DIR = libft/
LIBFT_LIB = libft.a

SRC_DIR = srcs/
SRCS = main.c fdf_utils.c get_next_line.c parsing.c

all :
	$(MAKE) -C $(LIBFT_DIR) all
	$(CC) -L$(MLX) $(MLX_FLAGS) $(addprefix $(SRC_DIR), $(SRCS)) $(LIBFT_DIR)$(LIBFT_LIB)

fclean : 
	$(RM) $(RMFLAGS) $(wildcard *.o)
	$(RM) $(RMFLAGS) $(NAME)

.PHONY : fclean all
