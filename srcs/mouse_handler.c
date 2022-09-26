/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:09:04 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/26 17:54:08 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	mouse_press(int button, int x, int y, void *param)
{
	t_info	*info = (t_info *)param;
		
	(void)x;
	(void)y;
	if (button == MOUSE_BTN_PRESS) //scroll up
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

int	mouse_release(int button, int x, int y, void *param)
{
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	return (0);
}
