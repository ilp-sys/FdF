/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:07:20 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/20 10:06:13 by jiwahn           ###   ########.fr       */
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

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"

# define DEFAULT_COLOR 42

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			53

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

//parsing.c
t_map	get_input(int argc, char *argv[]);

//fdf_utils.c
void	err_exit(const char *err_str);

#endif
