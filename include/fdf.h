/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:40:07 by yberries          #+#    #+#             */
/*   Updated: 2020/01/29 03:48:26 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

# define COLOR	0x00FBCF
# define COLORZ 0xCC00CC
# define MAX(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)
# define ESC	53

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img;
	int			**matrix;
	int			zoom;
	int			color;
	int			colors;
	int			x;
	int			y;
	int			xshift;
	int			yshift;
	float			height;
	float			rotate;

}				t_fdf;

int		key_press(int keycode, t_fdf *fdf);
void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);

#endif
