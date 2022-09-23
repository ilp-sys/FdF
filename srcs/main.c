/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:08:35 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/23 14:31:50 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc == 2)
	{
		info.mlx = mlx_init();
		info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "fdf");

		init_img(&info);
		info.map = get_input(argv);
		//render(&info);
		mlx_loop_hook(info.mlx, &render, &info);
		event_handler(&info);
		mlx_loop(info.mlx);
	}
	err_exit("Usage) ./FdF [map_path]");
}
