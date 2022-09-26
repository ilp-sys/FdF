/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:39:21 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/26 17:55:05 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/FdF.h"

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

void	draw_line(t_pnt pnt1, t_pnt pnt2, t_info *info)
{
	t_pnt	delta;
	t_pnt	sign;
	t_pnt	cur;
	int		error[2];

	delta.x = abs(pnt2.x - pnt1.x);
	delta.y = abs(pnt2.y - pnt1.y);
	sign.x = pnt1.x < pnt2.x ? 1 : -1;
	sign.y = pnt1.y < pnt2.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = pnt1;
	while (cur.x != pnt2.x || cur.y != pnt2.y)
	{
		put_pixel_to_img(cur.x, cur.y, pnt1.color, info);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

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

int	render(t_info *info)
{
	int		i;
	int		j;
	t_map	map = info->map;

	i = 0;
	clear_window(info);
	while (i < map.col)
	{
		j = 0;
		while (j < map.row)
		{
			if (i + 1 < map.col)
				draw_line(project(map.data[i][j], info), project(map.data[i + 1][j], info), info);
			if (j + 1 < map.row)
				draw_line(project(map.data[i][j], info), project(map.data[i][j + 1], info), info);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img_ptr, 0, 0);
	return (0);
}
