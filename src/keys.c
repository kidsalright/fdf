/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 06:30:54 by yberries          #+#    #+#             */
/*   Updated: 2020/02/04 23:02:23 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	some_key(int keycode, t_fdf *data)
{
	if (keycode == 43)
	{
		if (data->scale_x > 2)
			data->scale_x -= 2;
	}
	if (keycode == 47)
		data->scale_x += 2;
	if (keycode == 45)
		data->scale_z -= 2;
	if (keycode == 46)
		data->scale_z += 2;
	if (keycode == 44)
	{
		data->col1 += 5;
		data->col2 += 5;
	}
	if (keycode == 3)
		data->dott = ((data->dott == 1) ? 0.001 : 1);
}

void	rot_key(int keycode, t_fdf *data)
{
	if (keycode == 0)
		data->rot_y += 4;
	if (keycode == 2)
		data->rot_y -= 4;
	if (keycode == 1)
		data->rot_x += 4;
	if (keycode == 13)
		data->rot_x -= 4;
	if (keycode == 12)
		data->rot_z += 4;
	if (keycode == 14)
		data->rot_z -= 4;
}

void	res_key(t_fdf *data)
{
	data->rot_x = 245;
	data->rot_y = 110;
	data->rot_z = -125;
	data->scale_x = 25;
	data->scale_z = 10;
	data->col1 = 0x008080;
	data->col2 = 0xDB3BD1;
	data->dott = 1;
}

int		key_hook(int keycode, t_fdf *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	if ((keycode >= 0 && keycode < 3) || (keycode > 11 && keycode < 15))
		rot_key(keycode, data);
	if (keycode == 15)
		res_key(data);
	if ((keycode >= 43 && keycode <= 47) || keycode == 3)
		some_key(keycode, data);
	key_pressed(data);
	return (0);
}

void	key_pressed(t_fdf *data)
{
	t_fdf datacpy;

	datacpy = *data;
	datacpy.matrix = coordscopy(data);
	mlx_clear_window(0, data->win_ptr);
	scale(&datacpy, datacpy.scale_x, datacpy.scale_z);
	rotate_x(data->rot_x, &datacpy);
	rotate_y(data->rot_y, &datacpy);
	rotate_z(data->rot_z, &datacpy);
	center_map(&datacpy);
	draw_map(datacpy);
	free_data(datacpy);
}
