# include "fdf.h"

void	zoom(t_fdf *fdf)
{
	int	x;
	int	y;

	fdf->zoom = 28;
	y = 0;
	x = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			fdf->map->points[y][x].sx = fdf->map->points[y][x].x * fdf->zoom;
			fdf->map->points[y][x].sy = fdf->map->points[y][x].y * fdf->zoom;
			x++;
		}
		y++;
	}
}
