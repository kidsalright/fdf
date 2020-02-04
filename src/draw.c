/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 05:44:58 by yberries          #+#    #+#             */
/*   Updated: 2020/02/04 22:43:58 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_line(t_coords dot1, t_coords dot2, t_fdf *data)
{
	float		step;
	float		len;
	int			col;
	t_coords	matrix;

	len = 0;
	if (dot1.col == 1 || dot2.col == 1)
		col = data->col2;
	else
		col = data->col1;
	step = (1 / ((float)MAX(ABS((dot1.x - dot2.x)), \
					ABS((dot1.z - dot2.z))) * 2));
	while (len <= data->dott)
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
