# include "fdf.h"

void	zoom(t_fdf *fdf)
{
	int	x;
	int	y;

	if (fdf->w_width / fdf->map->width < fdf->w_heigth / fdf->map->height)
		fdf->zoom = (fdf->w_width / fdf->map->width / 1.8);
	else
		fdf->zoom = (fdf->w_heigth / fdf->map->height / 1.8);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			fdf->map->points[y][x].sx = fdf->map->points[y][x].x * fdf->zoom;
			fdf->map->points[y][x].sy = fdf->map->points[y][x].y * fdf->zoom;
			fdf->map->points[y][x].sz = fdf->map->points[y][x].z * fdf->zoom;
			x++;
		}
		y++;
	}
}

void	rotation(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			rotate_x(&fdf->map->points[y][x], fdf);
			rotate_y(&fdf->map->points[y][x], fdf);
			rotate_z(&fdf->map->points[y][x], fdf);
			x++;
		}
		y++;
	}
}

void	viewpoint(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			isometric(&fdf->map->points[y][x]);
			x++;
		}
		y++;
	}
}




