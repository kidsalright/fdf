/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:40:07 by yberries          #+#    #+#             */
/*   Updated: 2020/01/28 06:27:27 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

# define COLOR	0x00DDFF
# define COLORZ 0xBFFCFF
# define MAX(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)
# define ESC	53

typedef struct	s_fdf
{
	int			x;
	int			y;
	int			**matrix;
	int			zoom;
	int			color;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

void	read_file(char *file, t_fdf *data);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);

#endif
