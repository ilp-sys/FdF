/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:39:21 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/22 19:52:16 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/FdF.h"

# define ABS(X) ((X < 0) ? -(X) : X)

void	put_pixel_to_img(int x, int y, int color, t_info *info)
{
	int	i;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
	{
		i = (x * info->img.bpp / 8) + (y * info->img.size_l);
		printf("put pixel to data[%d]\n", i);
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

	delta.x = ABS(pnt2.x - pnt1.x);
	delta.y = ABS(pnt2.y - pnt1.y);
	sign.x = pnt1.x < pnt2.x ? 1 : -1;
	sign.y = pnt1.y < pnt2.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = pnt1;
	printf("draw line for (x:%d) (y:%d)\n", cur.x, cur.y);
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

void	render(t_info *info)
{
	t_map	map = info->map;
	//draw_background()
	for (int i = 0; i < info->map.row; i++)
	{
		for (int j = 0; j < info->map.col; j++)
		{
			//add projection
			draw_line(project(&map.data[i][j], map), project(&map.data[i + 1][j], map), info);
			draw_line(project(&map.data[i][j], map), project(&map.data[i][j + 1], map), info);
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img_ptr, 0, 0);
}
