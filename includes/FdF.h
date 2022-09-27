/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:07:20 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/27 14:25:23 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
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
# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			53
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}t_img;

typedef struct s_pnt
{
	int	x;
	int	y;
	int	z;
	int	color;
}t_pnt;

typedef struct s_map
{
	int		row;
	int		col;
	t_pnt	**data;
}t_map;

typedef struct s_info
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_map			map;
	int				offset_x;
	int				offset_y;
	unsigned int	zoom;
}t_info;

//main.c
void	err_exit(const char *err_str);
int		main(int argc, char *argv[]);

//parsing.c
t_map	get_input(char *argv[]);

//project.c
void	isometric(t_pnt *pnt);
t_pnt	project(t_pnt pnt, t_info *info);

//render.c
void	bresenham(t_pnt pnt1, t_pnt pnt2, t_info *info);
int		render(t_info *info);

//event_handler.c
void	event_handler(t_info *info);
int		mouse_press(int button, int x, int y, void *param);
int		key_press(int keycode, t_info *info);
int		kill(void);

//utils.c
void	swap(t_pnt *pnt);
int		get_split_cnt(char **splitted);
void	free_split(char **splitted);
void	err_exit(const char *err_str);

//init.c
void	init_img(t_info *info);
void	map_init(t_map *map);
void	initialize(t_info *info, char *argv[]);

//render_utils.c
void	clear_window(t_info *info);
void	put_pixel_to_img(int x, int y, int color, t_info *info);

#endif
