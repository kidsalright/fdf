/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 05:15:26 by yberries          #+#    #+#             */
/*   Updated: 2020/02/02 06:54:12 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	centermap(t_fdf *map)
{
	int	i;
	int	j;
	int	offset_x;
	int	offset_y;

	i = 0;
	offset_x = map->matrix[map->height / 2][map->width / 2].x;
	offset_y = map->matrix[map->height / 2][map->width / 2].z;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->matrix[i][j].x -= offset_x;
			map->matrix[i][j].x += WIN_X / 2;
			map->matrix[i][j].z -= offset_y;
			map->matrix[i][j].z += WIN_Y / 2;
			++j;
		}
		++i;
	}
}

void		scale(t_fdf *data, int xs, int ys)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->matrix[y][x].x *= xs;
			data->matrix[y][x].y *= xs;
			data->matrix[y][x].z *= ys;
			++x;
		}
		++y;
	}
}

t_coords	**coordscopy(t_fdf *data)
{
	t_coords	**new;
	int			x;
	int			y;

	y = 0;
	new  = (t_coords **)malloc(sizeof(t_coords *) * data->height);
	while (y < data->height)
	{
		new[y] = (t_coords *)malloc(sizeof(t_coords) * data->width);
		x = 0;
		while (x < data->width)
		{
			new[y][x] = data->matrix[y][x];
			++x;
		}
		++y;
	}
	return(new);
}

void		fdf_init(t_fdf *data)
{
	t_fdf	copy;

	data->scale_x = DEF_SCALE;
	data->scale_y = DEF_SCALE;
	data->rot_x = 245;
	data->rot_y = 110;
	data->rot_z = -125;
	copy = *data;
	copy.matrix = coordscopy(data);
	scale(&copy, data->scale_x, data->scale_y);
	rotate_x(data->rot_x, &copy);
	rotate_y(data->rot_y, &copy);
	rotate_z(data->rot_z, &copy);
	centermap(&copy);
	draw_map(copy);
}
