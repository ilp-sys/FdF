/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:07:20 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/17 16:09:36 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

# include <mlx.h>
# include "libft/libft.h"

# define BUFFER_SIZE 42

typedef struct s_pnt
{
	int	relief;
	int	color;
}t_pnt;

typedef struct s_map
{
	int		row;
	int		col;
	t_pnt	**data;
}t_map;

//main.c
int		main(int argc, char *argv[]);

//parsing.h
void	get_input(int argc, char *argv[]);

//fdf_utils.c
void	err_exit(const char *err_str);

#endif
