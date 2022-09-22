/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:08:17 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/22 19:52:11 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

t_pnt	project(t_pnt *pnt, t_map map)
{
	int	prev_x;
	int	prev_y;
	const int	zoom = (WIN_WIDTH / map.col <  WIN_HEIGHT / map.row ? WIN_WIDTH/ map.col : WIN_HEIGHT / map.row)/ 2;

	pnt->x *= zoom;
	pnt->y *= zoom;
	prev_x = pnt->x;
	prev_y = pnt->y;
	pnt->x = (prev_x - prev_y) * cos(0.523599);
	pnt->y = -pnt->z + (prev_x + prev_y) * sin(0.523599);
	return (*pnt);
}

