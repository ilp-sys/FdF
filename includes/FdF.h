/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:07:20 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/20 14:39:43 by jiwahn           ###   ########.fr       */
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

# define DEFAULT_COLOR 		0xFFFFFF

# define WIN_WIDTH			1920
# define WIN_HEIGHT			1080

# define IMG_WIDTH			100
# define IMG_HEIGHT			100

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			53

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}t_mlx;

//bpp		bits per pixel
//size_l	line length	
typedef struct	s_img
{
	void	*img_ptr;
	int		*data;	//or char *addr
	int		size_l;
	int		bpp;
	int		endian;
}t_img;

typedef struct	s_pnt
{
	int	relief;
	int	color;
}t_pnt;

typedef struct	s_map
{
	int		row;
	int		col;
	t_pnt	**data;
}t_map;

//main.c
int		main(int argc, char *argv[]);

//parsing.c
t_map	get_input(int argc, char *argv[]);

//project.c
void	project(t_mlx *mlx, t_map map);

//fdf_utils.c
void	err_exit(const char *err_str);

//mlx_utils.c

#endif
