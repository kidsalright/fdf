/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 03:52:26 by yberries          #+#    #+#             */
/*   Updated: 2020/01/29 03:48:34 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_fdf *data)
{
	int x;
	int	y;

	y = 0;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			if (x < data->x - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->y - 1)
				bresenham(x, y, x, y + 1, data);
			++x;
		}
		++y;
	}
}

void	isometric(float *x, float *y, int z, t_fdf fdf)
{
	float rot;

	rot = 1 + fdf.rotate;
	*x = (*x - *y) * cos(rot);
	*y = (*x + *y) * sin(rot) - z;
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	float		z;
	float		z1;

	if (data->height != 0)
		z = data->matrix[(int)y][(int)x];
	else
		z = data->matrix[(int)y][(int)x] * data->height + 10;
	if (data->height != 0)
		z1 = data->matrix[(int)y1][(int)x1] * data->height;
	else
		z1 = data->matrix[(int)y1][(int)x1];

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	data->color = (z || z1) ? (COLORZ + data->colors) : (COLOR + data->colors);
	isometric(&x, &y, z, *data);
	isometric(&x1, &y1, z1, *data);
	x += data->xshift;
	y += data->yshift;
	x1 += data->xshift;
	y1 += data->yshift;
	x_step = x1 - x;
	y_step = y1 - y;

	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}
