/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:46:34 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/12 17:24:34 by imoro-sa         ###   ########.fr       */
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
# define WIDTH 1400
# define HEIGHT 1100

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
	t_point			*point;
	t_map			*map;
	mlx_t			*mlx;
	mlx_image_t		*mlx_image;
	int				w_width;
	int				w_heigth;
	int				zoom;
	float			alpha;
	float			beta;
	float			gamma;
}					t_fdf;

//init_map
t_map		*map_size(char *argv);
void		map_init(t_map *map);
void		coordinates_xyz(char *argv, t_map *map);
void		get_altitude_and_rgb(char *argv, t_map *map);

//map_utils
int			wrd_counter(char *s, char c);
int			hex_to_decimal(char *buffer, int channel);
void		get_altitude(t_point *point, char *buffer);
void		get_rgb(t_point *point, char *buffer);

//drawing
t_fdf		*struct_init(t_map *map);
void		put_pixel(int pixel, t_point *point, t_fdf *fdf);
t_coord		*bresenham_coord(t_point *a, t_point *b);
void		bresenham(t_point *a, t_point *b, t_fdf *fdf);
void		draw(t_fdf *fdf);

//utils
void		ft_leaks(void);
void		error(char *err);
int			ft_abs(int n);
void		matrix_free(t_fdf *fdf);
void		split_free(char **buffer);

//perspective
void		zoom(t_fdf *fdf);
void		rotation(t_fdf *fdf);
void		viewpoint(t_fdf *fdf);
void		focus(t_fdf *fdf);

//perspective_utils
void		isometric(t_point *point);
int			*get_minimum(t_fdf *fdf);
void		rotate_x(t_point *point, t_fdf *fdf);
void		rotate_y(t_point *point, t_fdf *fdf);
void		rotate_z(t_point *point, t_fdf *fdf);

//hooks
void		hooks(void *struc);
void		close_window(t_fdf *fdf);
void		do_rotation_xy(t_fdf *fdf);
void		do_rotation_z(t_fdf *fdf);
void		do_translation(t_fdf *fdf);
void		do_zoom(t_fdf *fdf);


//hooks_utils
void		translate(t_fdf *fdf, char *buffer);

#endif


//RESOLVER:

//mapa de julia y fractol funcionan!
//no sé qué ha provocado el cambio.
//el único problema es que va lentísimo. posiblemente por split y gnl como dijo javi.

//zoom bonus
//zoom no está bien, ni el normal ni el bonus


//un botón para centrar la figura estaría bien (la c mismo)
//una función para centrar la iso

//cuando se traslada la figura, al luego rotarla spawnea en la posición inicial
//probablemente sea la estructura viewpoint que está mal




















//focus un poco mierdas:

// void	focus(t_fdf *fdf)
// {
// 	int	x;
// 	int	y;
// 	int	*min;

// 	y = 0;
// 	min = get_minimum(fdf);
// 	while (y < fdf->map->height)
// 	{
// 		x = 0;
// 		while (x < fdf->map->width)
// 		{
// 			fdf->map->points[y][x].sx -= min[0];
// 			fdf->map->points[y][x].sy -= min[1];
// 			fdf->map->points[y][x].sx += (fdf->w_width / 4) - (fdf->map->width * fdf->zoom / 4);
// 			fdf->map->points[y][x].sy += (fdf->w_heigth / 4) - (fdf->map->height * fdf->zoom / 4);
// 			x++;
// 		}
// 		y++;
// 	}
// 	free(min);
// }
