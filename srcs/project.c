/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:08:17 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/23 14:14:39 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	isometric(t_pnt *pnt)
{
	int	prev_x;
	int	prev_y;

	prev_x = pnt->x;
	prev_y = pnt->y;
	pnt->x = (prev_x - prev_y) * cos(0.523599);
	pnt->y = -pnt->z + (prev_x + prev_y) * sin(0.523599);
}

t_pnt	project(t_pnt *pnt, t_map map)
{
	const int	zoom = (WIDTH/map.col <  HEIGHT/map.row ? WIDTH/map.col : HEIGHT/map.row)/2;

	pnt->x *= zoom;
	pnt->y *= zoom;
	pnt->z *= zoom;
	pnt->x -= (map.col * zoom) / 2;
	pnt->y -= (map.row * zoom) / 2;
	isometric(pnt);
	pnt->x += WIDTH / 2;
	pnt->y += (HEIGHT + map.row * zoom) / 2;
	return (*pnt);
}

