/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:08:35 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/21 10:26:15 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int	kill(void *arg)
{
	(void)arg;
	exit(EXIT_SUCCESS);
}

void	init_img(t_info *info)
{
	info->img.img_ptr = mlx_new_image(info->mlx, IMG_WIDTH, IMG_HEIGHT);
	info->img.data = (int *)mlx_get_data_addr(info->img.img_ptr, &info->img.bpp, &info->img.size_l, &info->img.endian);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	//window init
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");

	init_img(&info);
	info.map = get_input(argc, argv);

	//key hook
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, NULL);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 0, &kill, NULL);

	mlx_loop_hook(info.mlx, &project, &info);

	mlx_loop(info.mlx);
	return (0);
}
