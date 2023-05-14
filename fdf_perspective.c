# include "fdf.h"

void	view(t_point *point)
{
	rotate_x(point);
	rotate_y(point);
	rotate_z(point);
	isometric(point);
}

void	translate(t_fdf *fdf)
{
	int	x;
	int	y;
	int	*min;

	y = 0;
	min = minimum(fdf);
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			fdf->map->points[y][x].sx -= min[0];
			fdf->map->points[y][x].sy -= min[1];
			x++;
		}
		y++;
	}
	free(min);
}

void	perspective(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	if (fdf->w_width / fdf->map->width < fdf->w_heigth / fdf->map->height)
		fdf->zoom = fdf->w_width / fdf->map->width / 2;
	else
		fdf->zoom = fdf->w_heigth / fdf->map->height / 2;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			fdf->map->points[y][x].sx = fdf->map->points[y][x].x * fdf->zoom;
			fdf->map->points[y][x].sy = fdf->map->points[y][x].y * fdf->zoom;
			fdf->map->points[y][x].sz = fdf->map->points[y][x].z * fdf->zoom;
			view(&fdf->map->points[y][x]);
			x++;
		}
		y++;
	}
	translate(fdf);
}


