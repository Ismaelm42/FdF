# include "fdf.h"

int	*minimum(t_fdf *fdf)
{
	int	x;
	int	y;
	int	*min;

	y = 0;
	min = (int *)malloc(sizeof(int) * 2);
	min[0] = fdf->map->points[0][0].sx;
	min[1] = fdf->map->points[0][0].sy;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (fdf->map->points[y][x].sx < min[0])
				min[0] = fdf->map->points[y][x].sx;
			if (fdf->map->points[y][x].sy < min[1])
				min[1] = fdf->map->points[y][x].sy;
			x++;
		}
		y++;
	}
	return (min);
}

void	rotate_x(t_point *point)
{
	point->sy = point->sy * cos(0) + point->sz * sin(0);
	point->sz = -point->sy * sin(0) + point->sz * cos(0);
}

void	rotate_y(t_point *point)
{
	point->sx = point->sx * cos(0) + point->sz * sin(0);
	point->sz = -point->sx * sin(0) + point->sz * cos(0);
}

void	rotate_z(t_point *point)
{
	point->sx = point->sx * cos(0) - point->sy * sin(0);
	point->sy = point->sx * sin(0) + point->sy * cos(0);
}

void	isometric(t_point *point)
{
	int	x;
	int	y;

	x = point->sx;
	y = point->sy;

	point->sx = (x - y) * cos(0.52);
	point->sy = (x + y) * sin(0.52) - point->sz;
}
