/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:09:04 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/22 19:31:15 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int	mouse_press(int button, int x, int y, void *param)
{
	//printf("mouse pressed B %d X %d Y %d\n", button, x, y);
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}

int	mouse_release(int button, int x, int y, void *param)
{
	//printf("mouse release B %d X %d Y %d\n", button, x, y);
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	//printf("mouse move X %d Y %d\n", x, y);
	(void)x;
	(void)y;
	(void)param;
	return (0);
}
