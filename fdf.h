/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:46:34 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/05 13:46:37 by imoro-sa         ###   ########.fr       */
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
# define WIDTH 1200
# define HEIGHT 900

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
	int				focus_x;
	int				focus_y;
}					t_fdf;


//init_map
t_map		*map_size(char *argv);
void		matrix_init(t_map *map);
void		coordinates_xyz(char *argv, t_map *map);
void		get_altitude_and_rgb(char *argv, t_map *map);


//map_utils
int			wrd_counter(char *s, char c);
int			hex_to_decimal(char *buffer, int channel);
void		get_altitude(t_point *point, char *buffer);
void		get_rgb(t_point *point, char *buffer);


//drawing
t_fdf		*map_init(t_map *map);
t_coord		*coord_init(t_point *a, t_point *b);
void		bresenham(t_point *a, t_point *b, t_fdf *fdf);
void		draw(t_fdf *fdf);


//draw_utils
void		draw_x(t_fdf *fdf);
void		draw_y(t_fdf *fdf);
void		put_pixel(int pixel, t_point *a, t_point *b, t_fdf *fdf);

//view
void		focus(t_fdf *fdf);


//utils
void		ft_leaks(void);
void		error(char *err);
int			ft_abs(int n);
void		swap(int *x, int *y);


//personal utils
void		printing_matrix(t_fdf *fdf);

#endif



// ** -------------------- recourses ----------------------------
// ** -------------- 3D -----------------------------------------
// **  x` = (x - y) * cos(angle);
// **  y` = (x + y) * sin(angle) - z;
// ** -------------------------------------------------------------
// **  ------ mlx_function ---------------------------------------
// **  void *mlx_ptr;
// **  void *win_ptr;
// **
// **  mlx_ptr = mlx_init();
// **  win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "FDF");
// **
// **  mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, #color);
// **
// **  mlx_key_hook(win_ptr, deal_key, NULL);
// **  mlx_loop(mlx_ptr);
// ** --------------------------------------------------------------
// ** ------ deal_key prototype ----------------------------------
// **  int  deal_key(int key, void *data);
// ** --------------------------------------------------------------
// ** colors:
// **  white = 0xffffff
// **  red = 0xe80c0c
// ** ----------------------------
// ** frameworks:
// **  -framework OpenGL -framework AppKit
// -----------------------------------------------------------------------------------------

// ** -------------- program structure ----------------------
// ** 1. read file
// **          - get height(how many lines) of text
// **          - get width(how many numbers in line)
// **          - allocate memory for **int by using width and height (look your ft_strsplit() )
// **          - read file and write number into **int matrix by using ft_strsplit() and atoi()
// **          - ps: ft_wdcounter(line, ' ');  is a function witch count words in line look your ft_strsplit( )

// ** -------------------------------------
// ** 2. drawing line function (google Bresenham algorithm)
// **             - find by how much we need to increase x and by how much we need to increase y
// **                          by using float. Example:
// **                                                       x = 2;           x1 = 4;
// **                                                       y = 2;           y1 = 6;
// **                                                       steps for x: 2
// **                                                       steps for y: 4
// **                          that means that y should grow 2 times faster than x
// **                          every loop step: y += 1 and x += 0.5
// **                          after 4 steps x and y will be equal with x1, y1
// **                                       real x:y                   x:y                      pixels:    
// **                    start:             2.0 : 2.0                  2:2                          .
// **                    step1:             2.5 : 3.0                  2:3                          .
// **                    step2:             3.0 : 4.0                  3:4                           .
// **                    step3:             3.5 : 5.0                  3:5                           . 
// **                    step4:             4.0 : 6.0                  4:6                            .
// **
// **                        that works because (float)2.5 turns to (int)2 in func. mlx_pixel_put()
// ** ------------------------------------------
// ** 3. function which draws lines between every dot
// **                     - example:
// **                                   0--        0--       0--      0
// **                                    |         |         |        |
// **                                   0--       10--      10--      0
// **                                    |         |         |        |
// **                                   0--       10--      10--      0
// **                                    |         |         |        |
// **                                   0--        0--       0--      0
// **                                '--' and '|' are lines between dots 
// **                              every dot has two lines (right and down):
// **
// **
// **
// **
// **
// **-----------------------------------------------------------------------------------------------------
// **
// **
// **
// ** 4. adding 3D
// **        - change coordinates by using isometric formulas:
// **              x` = (x - y) * cos(angle)
// **              y` = (x + y) * sin(angle) - z
// **        - x` and y` are coordinates in 3D format (default angle 0.8)
// ** ----------------
// ** 5. adding bonuses (move, rotation, zoom)
// **        - when you press button on keyboard the func. mlx_key_hook(win_ptr, deal_key, NULL);
// **                   call the func. deal_key.
// **        - In the deal key func. you have to change some parameters, clear the window with
// **                   mlx_clear_window(mlx_ptr, win_ptr); and redraw the picture
// ** ----------------
// ** 6. error handling
// **          - check if argc == 2
// **          - check if file exists: fd = open(file_name, O_RDONLY)
// **                         fd should be more than 0
// ** ----------------
// ** 7. fix leaks
// **         - type leaks a.out or leaks fdf in your shell

// escala de x e y? hacerlo dependiendo del número de parametro que me den?
// función para pintar los segmentos de punto a punto.


//algoritmo con problemas en paralelas a x, perpendiculares y valores negativos.
//a tener en cuenta que el eje y está invertido. el eje x está bien
//tiene una inclinación de 45º el eje y
//para entender mejor, realizar bresenham(0, 0, 1, 100, fdf);



// void	original_bresenham(int x0, int y0, int x1, int y1, t_fdf *fdf)
// {
// 	int		dx;
// 	int		dy;
// 	int		inc_x;
// 	int		inc_y;
// 	int		p;

// 	fdf = (void *)fdf;
// 	dx = abs_n(x1 - x0);
// 	dy = abs_n(y1 - y0);
// 	inc_x = 1;
// 	if ((x1 - x0) <= 0)
// 		inc_x = -1;
// 	inc_y = 1;
// 	if ((y1 - y0) <= 0)
// 		inc_y = -1;
// 	p = (2 * dy) - dx;
// 	while ((x0 <= x1) || (y0 <= y1))
// 	{
// 		mlx_put_pixel (fdf->mlx_image, x0, y0, 0xFFFFFF);
// 		if (p < 0)
// 			p = p + 2 * dy;
// 		else
// 		{
// 			y0 = y0 + inc_y;
// 			p = p + (2 * dy) - (2 * dx);
// 		}
//		x0 = x0 + inc_x;
// 		printf("x0 = %d\n", x0);
// 		printf("y0 = %d\n", y0);
// 		printf("x1 = %d\n", x1);
// 		printf("y1 = %d\n", y1);
// 		printf("\n");
// 	}
// }

//faltaria centrar aun
//resolver la z, investigar en cuanto al zoom, radians, vistas, etc.

//proyeccion rara de cojones con las coordenadas correctas
//puede ser de la función put_pixel?
