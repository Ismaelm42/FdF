# include "fdf.h"

t_fdf	*map_init(t_map *map)
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
	coord->dx = ft_abs(b->sx - a->sx);
	coord->dy = -ft_abs(b->sy - a->sy);
	if (a->sx < b->sx)
		coord->inc_x = 1;
	else
		coord->inc_x = -1;
	if (a->sy < b->sy)
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
		mlx_put_pixel(fdf->mlx_image, a->sx, a->sy, 0xFFFFFF);
		if (a->sx == b->sx && a->sy == b->sy)
			break ;
		coord->err_2 = 2 * coord->err;
		if (coord->err_2 >= coord->dy)
		{
			coord->err = coord->err + coord->dy;
			a->sx = a->sx + coord->inc_x;
		}	
		if (coord->err_2 <= coord->dx)
		{
			coord->err = coord->err + coord->dx;
			a->sy = a->sy + coord->inc_y;
		}
	}
}

void	draw(t_fdf *fdf)
{
	draw_x(fdf);
	draw_y(fdf);
}

void	draw_y(t_fdf *fdf)
{
	t_point	*point;
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < (fdf->map->height))
	{
		x = 0;
		while (x < (fdf->map->width - 1))
		{
			point = &fdf->map->points[y][x + 1];
			bresenham(&fdf->map->points[y][x], point, fdf);
			x++;
		}
		y++;
	}
}
void	draw_x(t_fdf *fdf)
{
	t_point	*point;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < (fdf->map->width))
	{
		y = 0;
		while (y < (fdf->map->height - 1))
		{
			point = &fdf->map->points[y + 1][x];
			bresenham(&fdf->map->points[y][x], point, fdf);
			y++;
		}
		x++;
	}
}
