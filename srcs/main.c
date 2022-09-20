/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:08:35 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/20 21:12:45 by jiwahn           ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_img	img;
	t_map	map;

	//window init
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");

	//init image
	img.img_ptr = mlx_new_image(mlx.mlx, IMG_WIDTH, IMG_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);

	//parse map
	map = get_input(argc, argv);

	//key hook
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, &key_press, NULL);
	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, &kill, NULL);

	mlx_loop_hook(mlx.mlx, &project, &mlx);

	mlx_loop(mlx.mlx);
	return (0);
}
