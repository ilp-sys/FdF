/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:39:21 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/20 14:37:00 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/FdF.h"

void	project(t_mlx *mlx, t_map map)
{
	t_img	img;

	img.img_ptr = mlx_new_image(mlx->mlx, IMG_WIDTH, IMG_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);

	// while x while till img.hieght and img.width
	// fill img data
	
	for (int i = 0; i < map.row; i++)
	{
		for (int j = 0; j < map.col; j++)
		{
			img.data[i * 10 + j] = map.data[i][j].color;
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img_ptr, 0, 0);
}
