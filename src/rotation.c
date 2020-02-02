/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 05:35:16 by yberries          #+#    #+#             */
/*   Updated: 2020/02/02 06:45:36 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(float angle, t_fdf *map)
{
	float	y1;
	float	z1;
	int		x;
	int		y;

	angle *= 0.01745329252;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			z1 = map->matrix[y][x].z * cos(angle) - map->matrix[y][x].y * sin(angle);
			y1 = map->matrix[y][x].y * cos(angle) + map->matrix[y][x].z	* sin(angle);
			map->matrix[y][x].y = y1;
			map->matrix[y][x].z = z1;
			++x;
		}
		++y;
	}
}

void	rotate_z(float angle, t_fdf *map)
{
	float	x1;
	float	z1;
	int		x;
	int		y;

	y = 0;
	angle = angle * 0.01745329252;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			x1 = map->matrix[y][x].z * cos(angle) + map->matrix[y][x].x * sin(angle);
			z1 = map->matrix[y][x].x * cos(angle) - map->matrix[y][x].z * sin(angle);
			map->matrix[y][x].x = x1;
			map->matrix[y][x].z = z1;
			++x;
		}
		++y;
	}
}

void	rotate_y(float angle, t_fdf *map)
{
	float	x1;
	float	y1;
	int		y;
	int		x;

	y = 0;
	angle = angle * 0.01745329252;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			x1 = map->matrix[y][x].y * cos(angle) - map->matrix[y][x].x * sin(angle);
			y1 = map->matrix[y][x].y * sin(angle) + map->matrix[y][x].x * cos(angle);
			map->matrix[y][x].x = x1;
			map->matrix[y][x].y = y1;
			++x;
		}
		++y;
	}
}
