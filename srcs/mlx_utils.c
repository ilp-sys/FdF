/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:10:27 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/26 17:13:28 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int	kill(void)
{
	exit(EXIT_SUCCESS);
}

void	init_img(t_info *info)
{
	info->img.img_ptr = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img.data = mlx_get_data_addr(info->img.img_ptr, &info->img.bpp, &info->img.size_l, &info->img.endian);
}

void	event_handler(t_info *info)
{
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &key_press, NULL);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, &kill, NULL);
	mlx_hook(info->win, MOUSE_BTN_PRESS, 0, &mouse_press, info);
	//mlx_hook(info->win, MOUSE_BTN_RELEASE, 0, &mouse_release, info);
	//mlx_hook(info->win, MOUSE_MOVE, 0, &mouse_move, info);
	//mlx_mouse_hook(info->win, mouse_scroll, *info.mouse);
}

void	initialize(t_info *info, char *argv[])
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "fdf");
	init_img(info);
	info->zoom = 1;
	info->map = get_input(argv);
}
