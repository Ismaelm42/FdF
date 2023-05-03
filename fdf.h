/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:24:02 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/03 13:04:18 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# define ERR_ACCESS "File opening error\n"
# define ERR_INPUT "File is not a valid map\n"
# define ERR_MAP_SIZE "Map size is not valid\n"

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			colour;
}		t_point;

typedef struct s_map
{
	long long	size;
	int			width;
	int			height;
	t_point		*points;
}		t_map;

//init_map
int		elts_counter(char *buffer);
t_map	map_file_check(char *argv, t_map map);

//point_init
t_point	init_point(t_point p, char *argv, t_map map);

//utils
void	error(char *err);

//points
//es una estructura de t_point, un array
//se puede guardar de la siguiente manera: malloc(sizeof(t_point) * size)
//hay que castear el malloc a (t_point *)
//esto se guardaría en un *array
//para avanzar de nivel, hacerlo en un **array
//quizás sea más simple hacerlo en un **array

#endif
