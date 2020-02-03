/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 06:30:54 by yberries          #+#    #+#             */
/*   Updated: 2020/02/03 08:04:58 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_rot(int keycode, t_fdf *data)
{
	if (keycode == 12)
		data->rot_y += 10;
	if (keycode == 14)
		data->rot_y -= 10;
	if (keycode == 13)
		data->rot_x += 10;
	if (keycode == 1)
		data->rot_x -= 10;
	if (keycode == 0)
		data->rot_z += 10;
	if (keycode == 2)
		data->rot_z -= 10;
}

void	key_scale(int keycode, t_fdf *data)
{
	if (keycode == 123)
		data->scale_x -= 2;
	if (keycode == 124)
		data->scale_x += 2;
	if (keycode == 126)
		data->scale_z += 2;
	if (keycode == 125)
		data->scale_z -= 2;
}

void	key_reset(t_fdf *data)
{
	data->rot_y = 110;
	data->rot_z = -125;
	data->rot_x = 245;
	data->scale_x = 25;
	data->scale_z = 10;
}

int		key_hook(int keycode, t_fdf *data)
{
	t_fdf datacpy;

	datacpy = *data;
	datacpy.matrix = coordscopy(data);
	printf("%d KEY \n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 15)
		key_reset(data);
	else if (keycode >= 0 && keycode <= 14)
		key_rot(keycode, data);
	else if (keycode >= 123 && keycode <= 126)
		key_scale(keycode, data);
	mlx_clear_window(0, data->win_ptr);
	scale(&datacpy, datacpy.scale_x, datacpy.scale_z);
	rotate_x(data->rot_x, &datacpy);
	rotate_y(data->rot_y, &datacpy);
	rotate_z(data->rot_z, &datacpy);
	centermap(&datacpy);
	draw_map(datacpy);
	free_data(datacpy);
	return (0);
}
