/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 02:48:37 by yberries          #+#    #+#             */
/*   Updated: 2020/02/03 07:32:57 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coords	map_coords(int x, int y, int z)
{
	t_coords	map;

	map.x = x;
	map.y = y;
	map.z = z;
	if (map.z > 0)
		map.col = 1;
	else
		map.col = 0;
	return (map);
}

void		matrix(int fd, t_fdf *data, t_coords ***stack)
{
	t_coords	**map;
	char		**nums;
	char		*line;
	int			x;
	int			y;

	y = 0;
	map = (t_coords **)malloc(sizeof(t_coords*) * (data->height));
	while (get_next_line(fd, &line))
	{
		map[y] = (t_coords *)malloc(sizeof(t_coords) * (data->width));
		nums = ft_strsplit(line, ' ');
		x = 0;
		while (nums[x])
		{
			map[y][x] = map_coords(x, y, ft_atoi(nums[x]));
			free(nums[x]);
			++x;
		}
		free(nums);
		free(line);
		++y;
	}
	close(fd);
	*stack = map;
}

void		read_file(char *file, t_fdf *data, t_coords ***map)
{
	char	*line;
	int		width;
	int		fd;

	if (!((fd = open(file, O_RDONLY)) >= 0))
		ft_error("Error can't open file.");
	data->height = 0;
	data->width = 0;
	while (get_next_line(fd, &line))
	{
		width = ft_countwords(line, ' ');
		if (data->width != 0 && data->width != width)
			ft_error("Error invalid line.");
		data->width = width;
		++data->height;
	}
	free(line);
	close(fd);
	fd = open(file, O_RDONLY);
	matrix(fd, data, map);
}
