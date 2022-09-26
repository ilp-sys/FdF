/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:39:21 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/26 20:11:17 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

static void	set_delta(t_pnt *delta, t_pnt pnt1, t_pnt pnt2)
{
	delta->x = abs(pnt2.x - pnt1.x);
	delta->y = abs(pnt2.y - pnt1.y);
}

static void	set_sign(t_pnt *sign, t_pnt pnt1, t_pnt pnt2)
{
	if (pnt1.x < pnt2.x)
		sign->x = 1;
	else
		sign->x = -1;
	if (pnt1.y < pnt2.y)
		sign->y = 1;
	else
		sign->y = -1;
}

void	bresenham(t_pnt pnt1, t_pnt pnt2, t_info *info)
{
	t_pnt	delta;
	t_pnt	sign;
	t_pnt	cur;
	int		error[2];

	set_delta(&delta, pnt1, pnt2);
	set_sign(&sign, pnt1, pnt2);
	error[0] = delta.x - delta.y;
	cur = pnt1;
	while (cur.x != pnt2.x || cur.y != pnt2.y)
	{
		put_pixel_to_img(cur.x, cur.y, pnt1.color, info);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
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

int	render(t_info *info)
{
	int		i;
	int		j;
	t_map	map;

	i = 0;
	map = info->map;
	clear_window(info);
	while (i < map.col)
	{
		j = 0;
		while (j < map.row)
		{
			if (i + 1 < map.col)
				bresenham(project(map.data[i][j], info), \
						project(map.data[i + 1][j], info), info);
			if (j + 1 < map.row)
				bresenham(project(map.data[i][j], info), \
						project(map.data[i][j + 1], info), info);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img_ptr, 0, 0);
	return (0);
}
