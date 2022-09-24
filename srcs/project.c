/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:08:17 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/24 17:23:03 by jiwahn           ###   ########.fr       */
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

t_pnt	project(t_pnt pnt, t_map map)
{
	const int	zoom = 5;
	(void)map;
	swap(&pnt);
	pnt.x *= zoom;
	pnt.y *= zoom;
	pnt.z *= zoom;
	isometric(&pnt);
	pnt.x += 50;
	pnt.y += 50;
	return (pnt);
}

