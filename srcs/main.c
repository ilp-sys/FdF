/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:08:35 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/26 18:05:48 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc == 2)
	{
		initialize(&info, argv);
		mlx_loop_hook(info.mlx, &render, &info);
		event_handler(&info);
		mlx_loop(info.mlx);
	}
	err_exit("Usage) ./FdF [map_path]");
}
