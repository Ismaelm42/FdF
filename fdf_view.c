# include "fdf.h"

void	focus(t_fdf *fdf)
{
	int	x;
	int	y;

	fdf->zoom = 40;//(WIDTH / fdf->map->width) / 2;
	fdf->focus_x = (WIDTH / fdf->map->width);
	fdf->focus_y = 200;//(HEIGHT / fdf->map->height);
	y = 0;
	x = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			fdf->map->points[y][x].sx = fdf->map->points[y][x].x * fdf->zoom \
			+ fdf->focus_x;
			fdf->map->points[y][x].sy = fdf->map->points[y][x].y * fdf->zoom \
			+ fdf->focus_y;
			// if (fdf->map->points[y][x].y == 0)
			// 	printf("fdf->map->points[%d][%d].sy = %d\n", y, x, fdf->map->points[y][x].sy);
			x++;
		}
		y++;
	}
}
