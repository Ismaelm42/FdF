# include "fdf.h"

t_fdf	*struct_init(t_map *map)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		error(ERR_MEM);
	fdf->map = map;
	fdf->mlx = mlx_init(WIDTH, HEIGTH, "fdf", true);
	if (!fdf->mlx)
		error(ERR_MLX);
	return (fdf);
}

t_coord	*coord_init(t_point *a, t_point *b)
{
	t_coord	*coord;

	coord = (t_coord *)malloc(sizeof(t_coord));
	if (coord == NULL)
		error(ERR_MEM);
	coord->dx = ft_abs(b->x - a->x);
	coord->dy = -ft_abs(b->y - a->y);
	if (a->x < b->x)
		coord->inc_x = 1;
	else
		coord->inc_x = -1;
	if (a->y < b->y)
		coord->inc_y = 1;
	else
		coord->inc_y = -1;
	coord->err = coord->dx + coord->dy;
	return (coord);
}

void	bresenham(t_point *a, t_point *b, t_fdf *fdf)
{
	t_coord	*coord;

	coord = coord_init(a, b);
	while (1)
	{
		mlx_put_pixel(fdf->mlx_image, a->x, a->y, 0xFFFFFF);
		if (a->x == b->x && a->y == b->y)
			break ;
		coord->err_2 = 2 * coord->err;
		if (coord->err_2 >= coord->dy)
		{
			coord->err = coord->err + coord->dy;
			a->x = a->x + coord->inc_x;
		}	
		if (coord->err_2 <= coord->dx)
		{
			coord->err = coord->err + coord->dx;
			a->y = a->y + coord->inc_y;
		}
	}
}

void	draw(t_fdf *fdf)
{
	t_point	*next;
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (fdf->map->points[y][x].y < (fdf->map->height - 1))
	{
		x = 0;
		while (fdf->map->points[y][x].x < (fdf->map->width - 1))
		{
			next = &fdf->map->points[y][x + 1];
			bresenham(&fdf->map->points[y][x], next, fdf);
			x++;
		}
		y++;
	}
	//igual habria que dejar y y x solo, en vez de fdf->map->points[y][x].y
}
