/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:10:27 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/26 19:29:54 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	key_press(int keycode)
{
	if (keycode == KEY_ESC)
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
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &key_press, NULL);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, &kill, NULL);
	mlx_hook(info->win, MOUSE_BTN_PRESS, 0, &mouse_press, info);
}
