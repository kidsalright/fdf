/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:50:38 by yberries          #+#    #+#             */
/*   Updated: 2020/01/31 05:36:10 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int err)
{
	if (err == 1)
		ft_putendl("Open error");
	else if (err == 2)
		ft_putendl("Invalid file");
	exit(err);
}

void	*mlx(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1500, 1400, "fdf");
//	data->img_ptr = mlx_new_image(data->mlx_ptr, 500, 400);
//	data->img = mlx_get_data_addr(data->img_ptr, &bits_per_pixel, &size_line, &endian);
//	data->zoom = 40;
//	data->xshift = 450;
//	data->yshift = 350;
	mlx_hook(data->win_ptr, 2, 0, key_press, data);
	mlx_loop(data->mlx_ptr);

}

int		main(int argc, char **argv)
{
	t_fdf		*data;
	int			fd;

	if (argc != 2)
	{
		ft_putendl("usage: ./fdf [file.fdf]");
		exit(3);
	}
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	mlx(data);
	return (0);
}
