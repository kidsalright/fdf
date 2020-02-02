/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 05:44:58 by yberries          #+#    #+#             */
/*   Updated: 2020/02/02 06:28:26 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_fabs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

float	ft_fmax(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void			draw_line(t_coords dot1, t_coords dot2, t_fdf *data)
{
	float		step;
	float		len;
	int			col;
	t_coords	matrix;

	len = 0;
	if (dot1.col == 1 || dot2.col == 1)
		col = 0xDB3BD1;
	else
		col = 0x008080;
	step = (float)(1 / (ft_fmax(ft_fabs(dot1.x - dot2.x), ft_fabs(dot1.z - dot2.z)) * 2));
	while (len <= 1)
	{
		matrix.x = dot1.x + len * (dot2.x - dot1.x);
		matrix.y = dot1.y + len * (dot2.y - dot1.y);
		matrix.z = dot1.z + len * (dot2.z - dot1.z);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, matrix.x, matrix.z, col);
		len += step;
	}
}

void		draw_map(t_fdf data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < data.height)
	{
			x = -1;
		while (++x < data.width)
		{
			if (y < data.height - 1)
				draw_line(data.matrix[y][x], data.matrix[y + 1][x], &data);
			if (x < data.width - 1)
				draw_line(data.matrix[y][x], data.matrix[y][x + 1], &data);
		}
	}
}
