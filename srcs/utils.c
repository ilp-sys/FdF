/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:33:58 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/26 19:41:52 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

void	err_exit(const char *err_str)
{
	perror(err_str);
	exit(EXIT_FAILURE);
}

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}

int	get_split_cnt(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		i++;
	return (i);
}

void	swap(t_pnt *pnt)
{
	int	tmp;

	tmp = pnt->x;
	pnt->x = pnt->y;
	pnt->y = tmp;
}
