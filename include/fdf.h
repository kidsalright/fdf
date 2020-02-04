/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:40:07 by yberries          #+#    #+#             */
/*   Updated: 2020/02/04 23:20:39 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

# define WIDTH 1200
# define HEIGHT 1000
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
	int			col1;
	int			col2;
	float		rot_x;
	float		rot_y;
	float		rot_z;
	float		dott;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img;
}				t_fdf;

void			ft_error(char *str);
void			read_file(char *file, t_fdf *data, t_coords ***matrix);
void			matrix_get(int fd, t_fdf *data, t_coords ***stack);
t_coords		matrix_coords(int x, int y, int z);
void			fdf_init(t_fdf *data);
t_coords		**coordscopy(t_fdf *data);
void			scale(t_fdf *data, int xs, int zs);
void			rotate_x(float angle, t_fdf *data);
void			rotate_y(float angle, t_fdf *data);
void			rotate_z(float angle, t_fdf *data);
void			center_map(t_fdf *data);
void			draw_map(t_fdf data);
void			draw_line(t_coords dot1, t_coords dot2, t_fdf *data);
void			free_data(t_fdf data);
int				key_hook(int keycode, t_fdf *data);
void			some_key(int keycode, t_fdf *data);
void			rot_key(int keycode, t_fdf *data);
void			res_key(t_fdf *data);
void			key_pressed(t_fdf *data);
int				ft_close(void *data);

#endif
