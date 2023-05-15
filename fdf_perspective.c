# include "fdf.h"

void	isometric(t_point *point)
{
	int	x;
	int	y;

	x = point->sx;
	y = point->sy;

	point->sx = (x - y) * cos(0.52);
	point->sy = (x + y) * sin(0.52) - point->sz;
}

void	view(t_point *point, t_fdf *fdf)
{
	rotate_x(point, fdf);
	rotate_y(point, fdf);
	rotate_z(point, fdf);
	isometric(point);
}

void	perspective(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	if (fdf->w_width / fdf->map->width < fdf->w_heigth / fdf->map->height)
		fdf->zoom = fdf->w_width / fdf->map->width / 1.8;
	else
		fdf->zoom = fdf->w_heigth / fdf->map->height / 1.8;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			fdf->map->points[y][x].sx = fdf->map->points[y][x].x * fdf->zoom;
			fdf->map->points[y][x].sy = fdf->map->points[y][x].y * fdf->zoom;
			fdf->map->points[y][x].sz = fdf->map->points[y][x].z * fdf->zoom;
			view(&fdf->map->points[y][x], fdf);
			x++;
		}
		y++;
	}
}

void	focus(t_fdf *fdf)
{
	int	x;
	int	y;
	int	*min;

	y = 0;
	min = get_minimum(fdf);
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			fdf->map->points[y][x].sx -= min[0];
			fdf->map->points[y][x].sy -= min[1];
			fdf->map->points[y][x].sx += (fdf->w_width / 2) - \
				(fdf->map->width * fdf->zoom / 2);
			fdf->map->points[y][x].sy += (fdf->w_heigth / 2) - \
				(fdf->map->height * fdf->zoom / 2);
			x++;
		}
		y++;
	}
	free(min);
}

