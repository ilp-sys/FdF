/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:39:21 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/21 10:26:44 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/FdF.h"

#include <stdio.h>
void	project(t_info *info)
{
	int	flag = 0;
	// n^2 till img.hieght and img.width
	// fill img data
	for (int i = 0; i < info->map.row; i++)
	{
		for (int j = 0; j < info->map.col; j++)
		{
			info->img.data[i * IMG_WIDTH + j] = info->map.data[i][j].color;
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img_ptr, 0, 0);
}
