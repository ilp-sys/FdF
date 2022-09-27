/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:28:43 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/27 14:14:12 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	initialize(t_info *info, char *argv[])
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "fdf");
	init_img(info);
	info->offset_x = 0;
	info->offset_y = 0;
	info->zoom = 1;
	info->map = get_input(argv);
}

void	init_img(t_info *info)
{
	info->img.img_ptr = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img.data = mlx_get_data_addr(info->img.img_ptr, \
			&info->img.bpp, &info->img.size_l, &info->img.endian);
}

void	map_init(t_map *map)
{
	map->row = 0;
	map->col = 0;
	map->data = NULL;
}
