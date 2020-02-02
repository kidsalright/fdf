/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 06:30:54 by yberries          #+#    #+#             */
/*   Updated: 2020/02/02 07:17:02 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_rot(int keycode, t_fdf *map)
{
	if (keycode == 12)
		map->rot_y += ANGL;
	if (keycode == 14)
		map->rot_y -= ANGL;
	if (keycode == 13)
		map->rot_x += ANGL;
	if (keycode == 1)
		map->rot_x -= ANGL;
	if (keycode == 0)
		map->rot_z += ANGL;
	if (keycode == 2)
		map->rot_z -= ANGL;
}

void	key_scale(int keycode, t_fdf *map)
{
	if (keycode == 123)
		map->scale_x -= 2;
	if (keycode == 124)
		map->scale_x += 2;
	if (keycode == 126)
		map->scale_y += 2;
	if (keycode == 125)
		map->scale_y -= 2;
}

void	key_reset(t_fdf *map)
{
	map->rot_y = 110;
	map->rot_z = -125;
	map->rot_x = 245;
	map->scale_x = DEF_SCALE;
	map->scale_y = DEF_SCALE;
}

int			key_hook(int keycode, t_fdf *map)
{
	t_fdf mapcpy;

	mapcpy = *map;
	mapcpy.matrix = coordscopy(map);
	printf("%d KEY \n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 15)
		key_reset(map);
	else if (keycode >= 0 && keycode <= 14)
		key_rot(keycode, map);
	else if (keycode >= 123 && keycode <= 126)
		key_scale(keycode, map);
	mlx_clear_window(0, map->win_ptr);
	scale(&mapcpy, mapcpy.scale_x, mapcpy.scale_y);
	rotate_x(map->rot_x, &mapcpy);
	rotate_y(map->rot_y, &mapcpy);
	rotate_z(map->rot_z, &mapcpy);
	centermap(&mapcpy);
	draw_map(mapcpy);
//	free_map(mapcpy);
	return (0);
}
