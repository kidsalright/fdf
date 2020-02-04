/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 05:15:26 by yberries          #+#    #+#             */
/*   Updated: 2020/02/04 22:52:34 by yberries         ###   ########.fr       */
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

void		center_map(t_fdf *data)
{
	int	shift_x;
	int	shift_y;
	int	x;
	int	y;

	y = -1;
	shift_x = data->matrix[data->height / 2][data->width / 2].x;
	shift_y = data->matrix[data->height / 2][data->width / 2].z;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			data->matrix[y][x].x -= shift_x;
			data->matrix[y][x].x += WIDTH / 2;
			data->matrix[y][x].z -= shift_y;
			data->matrix[y][x].z += HEIGHT / 2;
		}
	}
}

void		scale(t_fdf *data, int xs, int zs)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			data->matrix[y][x].x *= xs;
			data->matrix[y][x].y *= xs;
			data->matrix[y][x].z *= zs;
		}
	}
}

t_coords	**coordscopy(t_fdf *data)
{
	t_coords	**datacpy;
	int			x;
	int			y;

	y = -1;
	datacpy = (t_coords **)malloc(sizeof(t_coords *) * data->height);
	while (++y < data->height)
	{
		datacpy[y] = (t_coords *)malloc(sizeof(t_coords) * data->width);
		x = -1;
		while (++x < data->width)
			datacpy[y][x] = data->matrix[y][x];
	}
	return (datacpy);
}

void		fdf_init(t_fdf *data)
{
	t_fdf	datacpy;

	data->scale_x = 25;
	data->scale_z = 10;
	data->rot_x = 245;
	data->rot_y = 110;
	data->rot_z = -125;
	data->col1 = 0x008080;
	data->col2 = 0xDB3BD1;
	data->dott = 1;
	datacpy = *data;
	datacpy.matrix = coordscopy(data);
	scale(&datacpy, data->scale_x, data->scale_z);
	rotate_x(data->rot_x, &datacpy);
	rotate_y(data->rot_y, &datacpy);
	rotate_z(data->rot_z, &datacpy);
	center_map(&datacpy);
	draw_map(datacpy);
	free_data(datacpy);
}
