# include "fdf.h"

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

void	put_pixel(int pixel, t_point *a, t_point *b, t_fdf *fdf)
{
	fdf->mlx_image->pixels[pixel] = 255;
	fdf->mlx_image->pixels[pixel + 1] = 255;
	fdf->mlx_image->pixels[pixel + 2] = 255;
	fdf->mlx_image->pixels[pixel + 3] = 120;
	if (a->y == 0 && b->y == 0)
	{
		printf("a->x = %d\t| a->y = %d\n", a->x, a->y);
		printf("b->x = %d\t| b->y = %d\n", b->x, b->y);
		printf("a->sx = %d\t| a->sy = %d\n", a->sx, a->sy);
		printf("b->sx = %d\t| b->sy = %d\n", b->sx, b->sy);
	}
}
