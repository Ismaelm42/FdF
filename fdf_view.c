# include "fdf.h"

void	focus(t_fdf *fdf)
{
	int	x;
	int	y;

	fdf->zoom = 40;
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			// if (x == 1 && y == 0)
			// {
			// 	printf("x=1 ==%d\n", fdf->map->points[y][x].x);
			// 	printf("y=0 ==%d\n\n\n\n\n\n\n\n", fdf->map->points[y][x].y);
			// }
			fdf->map->points[y][x].sx = fdf->map->points[y][x].x * fdf->zoom;
			fdf->map->points[y][x].sy = fdf->map->points[y][x].y * fdf->zoom;
			// if (x == 1 && y == 0)
			// {
			// 	printf("sx=1 ==%d\n", fdf->map->points[y][x].sx);
			// 	printf("sy=0 ==%d\n\n\n\n\n\n\n\n", fdf->map->points[y][x].sy);
			// }
			x++;
		}
		y++;
	}
	// printf("AWsx=1 ==%d\n", fdf->map->points[0][1].sx);
	// printf("AWsy=0 ==%d\n\n\n\n\n\n\n\n", fdf->map->points[0][1].sy);
}
