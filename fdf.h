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
}		t_map;

//init_map
int		elts_counter(char *buffer);
t_map	map_file_check(char *argv, t_map map);

//point_init
t_point	init_point(t_point p, char *argv, t_map map);

//utils
void	error(char *err);


#endif
