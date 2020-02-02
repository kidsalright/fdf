/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yberries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:40:07 by yberries          #+#    #+#             */
/*   Updated: 2020/02/02 07:07:22 by yberries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

# define ESC	53
# define DEF_SCALE 20
# define WIN_X 1200
# define WIN_Y 1000
# define ANGL 5

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
	int			scale_y;
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
void			rotate_z(float angle, t_fdf *map); 					//change
void			rotate_x(float angle, t_fdf *map); 					//change
void			rotate_y(float angle, t_fdf *map); 					//change
void			centermap(t_fdf *data);
void			draw_map(t_fdf data);
void			draw_line(t_coords v1, t_coords v2, t_fdf *m);
float			ft_fmax(float a, float b);
float			ft_fabs(float a);


int				key_hook(int keycode, t_fdf *map);

#endif
