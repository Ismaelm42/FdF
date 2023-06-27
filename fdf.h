/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:46:34 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/22 13:27:13 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <math.h>
# define ERR_OPEN "File opening error\n"
# define ERR_INPUT "File is not a valid map\n"
# define ERR_MAP_SIZE "Map size is not valid\n"
# define ERR_MEM "Memory allocation failed\n"
# define ERR_MLX "Error opening MLX\n"
# define WIDTH 1800
# define HEIGHT 1200

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				sx;
	int				sy;
	int				sz;
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
	uint8_t			a;
}					t_point;

typedef struct s_map
{
	t_point			**points;
	char			*buffer;
	int				width;
	int				height;
}					t_map;

typedef struct s_coord
{	
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				inc_x;
	int				inc_y;
	int				err;
	int				err_2;
}					t_coord;

typedef struct s_fdf
{
	char			*argv;
	t_point			*point;
	t_map			*map;
	mlx_t			*mlx;
	mlx_image_t		*mlx_image;
	int				w_width;
	int				w_height;
	int				zoom;
	float			alpha;
	float			beta;
	float			gamma;
	int				viewpoint;
	int				*min_and_max;
}					t_fdf;

//parse
t_map		*map_size(char *argv);
void		map_init(t_map *map);
void		coordinates_xyz(char *argv, t_map *map);
void		get_altitude_and_rgb(char *argv, t_map *map);

//parse_utils
int			wrd_counter(char *s, char c);
int			hex_to_decimal(char *buffer, int channel);
void		get_altitude(t_point *point, char *buffer);
void		get_rgb(t_point *point, char *buffer);

//draw
t_fdf		*struct_init(t_map *map);
void		put_pixel(int pixel, t_point *point, t_fdf *fdf);
t_coord		*bresenham_coord(t_point *a, t_point *b);
void		bresenham(t_point *a, t_point *b, t_fdf *fdf);
void		draw(t_fdf *fdf);

//viewpoint
void		zoom(t_fdf *fdf);
void		rotation(t_fdf *fdf);
void		viewpoint(t_fdf *fdf);
void		focus(t_fdf *fdf);

//viewpoint_utils
void		get_min_and_max(t_fdf *fdf);
void		rotate_x(t_point *point, t_fdf *fdf);
void		rotate_y(t_point *point, t_fdf *fdf);
void		rotate_z(t_point *point, t_fdf *fdf);

//perspectives
void		isometric(t_point *point);
void		cavalier(t_point *point);

//utils
void		error(char *err);
int			ft_abs(int n);
void		matrix_free(t_fdf *fdf);
void		split_free(char **buffer);
void		set_array(int *array, int nbr, int length);

//hooks
void		hooks(void *struc);
void		close_window(t_fdf *fdf);
void		select_viewpoint(t_fdf *fdf);
void		do_translation(t_fdf *fdf);
void		do_zoom(t_fdf *fdf);

//hooks2
void		do_rotation_x(t_fdf *fdf);
void		do_rotation_y(t_fdf *fdf);
void		do_rotation_z(t_fdf *fdf);
void		do_inc_z(t_fdf *fdf);

//hooks_utils
void		re_draw(t_fdf *fdf);
void		translate(t_fdf *fdf, char *buffer);
void		inc_z(t_fdf *fdf, char *buffer);

#endif
