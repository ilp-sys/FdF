/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:39:21 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/20 22:29:29 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/FdF.h"

#include <stdio.h>
void	project(t_mlx *mlx, t_map map, t_img *img)
{
	int	flag = 0;
	// n^2 till img.hieght and img.width
	// fill img data
	for (int i = 0; i < map.row; i++)
	{
		for (int j = 0; j < map.col; j++)
		{
			printf("relief %d color %x\n", map.data[i][j].relief, map.data[i][j].color);
			img->data[i * IMG_WIDTH + j] = map.data[i][j].color;
			printf("i %d j %d insert into (%d)\n", i, j, i * IMG_WIDTH + j);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img_ptr, 0, 0);
}
