/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:12:32 by yberries          #+#    #+#             */
/*   Updated: 2020/01/29 03:56:23 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		esc_press(t_fdf *fdf)
{
	free(fdf);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	exit (0);
}

int		key_press(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		esc_press(fdf);
	if (keycode == 12)
	{
		if (fdf->zoom < 150)
			fdf->zoom++;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw(fdf);
	}
	if (keycode == 13)
	{
		if (fdf->zoom > 5)
			fdf->zoom--;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw(fdf);
	}
	int i = 0;
	int j = 0;
	if (keycode == 14)
	{
		fdf->height += 2.1;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw(fdf);
	}
	if (keycode == 15)
	{
		fdf->colors += 1000;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw(fdf);
	}
	if (keycode == 17)
	{
		fdf->rotate += 0.2;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw(fdf);
	}
	if (keycode == 49)
	{
		fdf->zoom = 20;
		fdf->height = 0;
		fdf->colors = 0;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw(fdf);
	}
	if (keycode == 123)
	{
		fdf->xshift -= 20;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw(fdf);
	}
	if (keycode == 124)
	{
		fdf->xshift += 20;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw(fdf);
	}
	if (keycode == 126)
	{
		fdf->yshift -= 20;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw(fdf);
	}
	if (keycode == 125)
	{
		fdf->yshift += 20;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw(fdf);
	}
}
