/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:08:17 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/26 17:19:07 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	swap(t_pnt *pnt)
{
	int tmp;

	tmp = pnt->x;
	pnt->x = pnt->y;
	pnt->y = tmp;
}

void	isometric(t_pnt *pnt)
{
	int	prev_x;
	int	prev_y;

	prev_x = pnt->x;
	prev_y = pnt->y;
	pnt->x = (prev_x - prev_y) * cos(M_PI / 3);
	pnt->y = -pnt->z + (prev_x + prev_y) * sin(M_PI / 3);
}

t_pnt	project(t_pnt pnt, t_info *info)
{
	swap(&pnt);
	pnt.x *= info->zoom;
	pnt.y *= info->zoom;
	pnt.z *= info->zoom;
	isometric(&pnt);
	pnt.x += WIDTH / 3;
	pnt.y += HEIGHT / 3;
	return (pnt);
}

