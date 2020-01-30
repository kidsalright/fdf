/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:50:38 by yberries          #+#    #+#             */
/*   Updated: 2020/01/30 05:25:03 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf		*fdf;
	int			fd;

	if (argc != 2)
	{
		ft_putendl("usage: ./fdf [file.fdf]");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Read error.");
		exit(1);
	}
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(argv[1], fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1500, 1400, "fdf");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 500, 400);
	fdf->img = mlx_get_data_addr(fdf->img_ptr, &bits_per_pixel, &size_line, &endian);
	fdf->zoom = 40;
	fdf->xshift = 450;
	fdf->yshift = 350;
	draw(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
