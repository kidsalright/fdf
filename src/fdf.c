/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 05:15:26 by yberries          #+#    #+#             */
/*   Updated: 2020/02/03 08:44:57 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_data(t_fdf data)
{
	int	i;

	i = 0;
	while (i < data.height)
	{
		free(data.matrix[i]);
		++i;
	}
	free(data.matrix);
}

void		centermap(t_fdf *data)
{
	int	offset_x;
	int	offset_y;
	int	x;
	int	y;

	y = 0;
	offset_x = data->matrix[data->height / 2][data->width / 2].x;
	offset_y = data->matrix[data->height / 2][data->width / 2].z;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->matrix[y][x].x -= offset_x;
			data->matrix[y][x].x += WIN_X / 2;
			data->matrix[y][x].z -= offset_y;
			data->matrix[y][x].z += WIN_Y / 2;
			++x;
		}
		++y;
	}
}

void		scale(t_fdf *data, int xs, int zs)
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
			data->matrix[y][x].z *= zs;
			++x;
		}
		++y;
	}
}

t_coords	**coordscopy(t_fdf *data)
{
	t_coords	**datacpy;
	int			x;
	int			y;

	y = 0;
	datacpy = (t_coords **)malloc(sizeof(t_coords *) * data->height);
	while (y < data->height)
	{
		datacpy[y] = (t_coords *)malloc(sizeof(t_coords) * data->width);
		x = 0;
		while (x < data->width)
		{
			datacpy[y][x] = data->matrix[y][x];
			++x;
		}
		++y;
	}
	return (datacpy);
}

void		fdf_init(t_fdf *data)
{
	t_fdf	datacpy;

	data->scale_x = 25;
	data->scale_z = 15;
	data->rot_x = 245;
	data->rot_y = 110;
	data->rot_z = -125;
	datacpy = *data;
	datacpy.matrix = coordscopy(data);
	scale(&datacpy, data->scale_x, data->scale_z);
	rotate_x(data->rot_x, &datacpy);
	rotate_y(data->rot_y, &datacpy);
	rotate_z(data->rot_z, &datacpy);
	centermap(&datacpy);
	draw_map(datacpy);
	free_data(datacpy);
}
