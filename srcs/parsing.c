/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:19:45 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/26 19:57:27 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

static void	read_map(int fd, t_list **map_buf)
{
	int		i;
	char	*line;

	i = 0;
	*map_buf = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line[ft_strlen(line) - 1] = '\0';
		ft_lstadd_back(map_buf, ft_lstnew(line));
		i++;
	}
}

static void	set_pnt(int i, int j, t_pnt *pnt, char *num_str)
{
	pnt->x = i;
	pnt->y = j;
	pnt->z = ft_atoi(num_str);
	pnt->color = DEFAULT_COLOR;
}

static void	fill_map(t_map *map, t_list *map_buf)
{
	int		i;
	int		j;
	char	**split_space;

	map->col = ft_lstsize(map_buf);
	map->data = (t_pnt **)malloc(sizeof(t_pnt) * map->col);
	if (!map->data)
		err_exit("malloc failed");
	i = -1;
	while (++i < map->col)
	{
		j = -1;
		split_space = ft_split(map_buf->content, ' ');
		(map->data)[i] = malloc(sizeof(t_pnt) * get_split_cnt(split_space));
		while (split_space[++j])
			set_pnt(i, j, &map->data[i][j], split_space[j]);
		if (!map->row)
			map->row = j;
		else if (map->row != j)
			err_exit("map error");
		free_split(split_space);
		map_buf = map_buf->next;
	}
}

t_map	get_input(char *argv[])
{
	int		fd;
	t_map	map;
	t_list	*map_buf;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		err_exit("open failed");
	read_map(fd, &map_buf);
	map_init(&map);
	fill_map(&map, map_buf);
	ft_lstclear(&map_buf, free);
	return (map);
}
