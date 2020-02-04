/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:50:38 by yberries          #+#    #+#             */
/*   Updated: 2020/02/04 22:40:14 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_close(void *data)
{
	(void)data;
	exit(0);
}

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

int		main(int argc, char **argv)
{
	t_fdf	data;

	if (argc != 2)
		ft_error("usage: ./fdf [file.fdf]");
	read_file(argv[1], &data, &data.matrix);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "FDF");
	fdf_init(&data);
	mlx_hook(data.win_ptr, 2, 0, key_hook, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_close, &data);
	mlx_loop(data.mlx_ptr);
}
