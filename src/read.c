/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 02:48:37 by yberries          #+#    #+#             */
/*   Updated: 2020/02/04 23:24:44 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coords	matrix_coords(int x, int y, int z)
{
	t_coords	matrix;

	matrix.x = x;
	matrix.y = y;
	matrix.z = z;
	if (matrix.z != 0)
		matrix.col = 1;
	else
		matrix.col = 0;
	return (matrix);
}

void		matrix_get(int fd, t_fdf *data, t_coords ***stack)
{
	t_coords	**matrix;
	char		**nums;
	char		*line;
	int			x;
	int			y;

	y = -1;
	matrix = (t_coords **)malloc(sizeof(t_coords*) * (data->height));
	while (get_next_line(fd, &line))
	{
		matrix[++y] = (t_coords *)malloc(sizeof(t_coords) * (data->width));
		nums = ft_strsplit(line, ' ');
		x = -1;
		while (nums[++x])
		{
			matrix[y][x] = matrix_coords(x, y, ft_atoi(nums[x]));
			free(nums[x]);
		}
		free(nums);
		free(line);
	}
	close(fd);
	*stack = matrix;
}

void		read_file(char *file, t_fdf *data, t_coords ***matrix)
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
		free(line);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	matrix_get(fd, data, matrix);
}
