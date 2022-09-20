/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:08:35 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/20 14:51:32 by jiwahn           ###   ########.fr       */
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
	t_mlx	*mlx;
	t_map	map;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	map = get_input(argc, argv);
	mlx_hook(mlx->win, X_EVENT_KEY_PRESS, 0, &key_press, NULL);
	mlx_hook(mlx->win, X_EVENT_KEY_EXIT, 0, &kill, NULL);
	mlx_loop_hook(mlx->mlx, &project, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
