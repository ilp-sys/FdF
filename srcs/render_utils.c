/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:06:03 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/26 20:11:44 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	clear_window(t_info *info)
{
	int		i;
	int		capa;
	t_img	img;

	i = 0;
	img = info->img;
	capa = WIDTH * HEIGHT * 4 - 1;
	while (i < capa)
		img.data[i++] = 0;
}

void	put_pixel_to_img(int x, int y, int color, t_info *info)
{
	int	i;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		i = (x * info->img.bpp / 8) + (y * info->img.size_l);
		info->img.data[i] = color;
		info->img.data[++i] = color >> 8;
		info->img.data[++i] = color >> 16;
	}
}
