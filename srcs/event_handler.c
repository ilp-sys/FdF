/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:10:27 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/27 14:25:40 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	key_press(int keycode, t_info *info)
{
	if (keycode == ARROW_UP)
	{
		if (info->offset_y > INT_MIN)
			info->offset_y--;
	}
	else if (keycode == ARROW_DOWN)
	{
		if (info->offset_y < INT_MAX)
			info->offset_y++;
	}
	else if (keycode == ARROW_LEFT)
	{
		if (info->offset_y > INT_MIN)
			info->offset_x--;
	}
	else if (keycode == ARROW_RIGHT)
	{
		if (info->offset_y < INT_MAX)
			info->offset_x++;
	}
	else if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int	kill(void)
{
	exit(EXIT_SUCCESS);
}

int	mouse_press(int button, int x, int y, void *param)
{
	t_info	*info;

	(void)x;
	(void)y;
	info = (t_info *)param;
	if (button == MOUSE_BTN_PRESS)
	{
		if (info->zoom < UINT_MAX)
			info->zoom += 1;
	}
	else if (button == MOUSE_BTN_RELEASE)
	{
		if (info->zoom > 0)
			info->zoom -= 1;
	}
	return (0);
}

void	event_handler(t_info *info)
{
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, &kill, NULL);
	mlx_hook(info->win, MOUSE_BTN_PRESS, 0, &mouse_press, info);
}
