/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:08:35 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/20 10:40:44 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*win;
	t_map	map;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "fdf");
	map = get_input(argc, argv);
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, NULL);
	mlx_loop(mlx);
	return (0);
}
