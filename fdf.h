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
# define ERR_OPEN "File opening error\n"
# define ERR_INPUT "File is not a valid map\n"
# define ERR_MAP_SIZE "Map size is not valid\n"
# define ERR_MEM "Memory allocation failed\n"

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
}				t_point;

typedef struct s_map
{
	t_point		**points;
	int			width;
	int			height;
}				t_map;

typedef struct s_fdf
{
	t_point		point;
	t_map		map;
}				t_fdf;

//init_map
t_map		*map_size(char *argv);
t_point		**matrix_init(t_map *map);
void		coordinates_xy(t_map *map, t_point **points);
void		get_altitude_and_rgb(char *argv, t_map *map, t_point **points);




//map_utils
int			hex_to_decimal(char *buffer, int channel);
void		get_altitude(t_point *point, char *buffer);
void		get_rgb(t_point *point, char *buffer);



//point_init
t_point		init_point(t_point p, char *argv, t_map map);







//utils
void		ft_leaks(void);
void		error(char *err);




#endif
