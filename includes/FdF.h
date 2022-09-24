/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:07:20 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/24 17:43:48 by jiwahn           ###   ########.fr       */
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

# define WIDTH				1920
# define HEIGHT				1080

# define X_EVENT_KEY_PRESS	2
# define MOUSE_BTN_PRESS	4
# define MOUSE_BTN_RELEASE	5
# define MOUSE_MOVE			6
# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			53

typedef struct s_mouse
{

}t_mouse;

//bpp		bits per pixel
//size_l	line length	
typedef struct	s_img
{
	void	*img_ptr;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}t_img;

typedef struct	s_pnt
{
	int	x;
	int	y;
	int	z;
	int	color;
}t_pnt;

typedef struct	s_map
{
	int		row;
	int		col;
	t_pnt	**data;
}t_map;

typedef struct	s_info
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
}t_info;

//main.c
int		main(int argc, char *argv[]);

//parsing.c
t_map	get_input(char *argv[]);

//project.c
t_pnt	project(t_pnt pnt, t_map map);

//render.c
int		render(t_info *info);

//fdf_utils.c
void	err_exit(const char *err_str);

//mlx_utils.c
int		key_press(int keycode);
int		kill(void);
void	init_img(t_info *info);
void	event_handler(t_info *info);

//mouse_handler.c
int		mouse_press(int button, int x, int y, void *param);
int		mouse_release(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);

#endif
