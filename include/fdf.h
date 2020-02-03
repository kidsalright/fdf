/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:40:07 by yberries          #+#    #+#             */
/*   Updated: 2020/02/03 08:28:32 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h> //remove!!!!

# define WIN_X 1200
# define WIN_Y 1000
# define MAX(a, b) (a > b ? a : b)
# define ABS(a) ((a < 0) ? -a : a)

typedef struct	s_coords
{
	int			x;
	int			y;
	int			z;
	int			col;
}				t_coords;

typedef struct	s_fdf
{
	int			width;
	int			height;
	t_coords	**matrix;
	int			scale_x;
	int			scale_z;
	float		rot_x;
	float		rot_y;
	float		rot_z;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img;

}				t_fdf;

void			ft_error(char *str);
void			read_file(char *file, t_fdf *data, t_coords ***map);
void			matrix(int fd, t_fdf *data, t_coords ***stack);
t_coords		map_coords(int x, int y, int z);
void			fdf_init(t_fdf *data);
t_coords		**coordscopy(t_fdf *data);
void			scale(t_fdf *data, int xs, int ys);
void			rotate_x(float angle, t_fdf *data);
void			rotate_y(float angle, t_fdf *data);
void			rotate_z(float angle, t_fdf *data);
void			centermap(t_fdf *data);
void			draw_map(t_fdf data);
void			draw_line(t_coords dot1, t_coords dot2, t_fdf *data);
void			free_data(t_fdf data);
int				key_hook(int keycode, t_fdf *data);
void			key_reset(t_fdf *data);
void			key_scale(int keycode, t_fdf *data);
void			key_rot(int keycode, t_fdf *data);

#endif
