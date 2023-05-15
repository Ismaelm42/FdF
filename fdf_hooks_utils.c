# include "fdf.h"

void	translate(t_fdf *fdf, char *buffer)
{	
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (ft_strnstr(buffer, "UP", 2) != NULL)
				fdf->map->points[y][x].sy -= 2;
			if (ft_strnstr(buffer, "DOWN", 4) != NULL)
				fdf->map->points[y][x].sy += 2;
			if (ft_strnstr(buffer, "LEFT", 2) != NULL)
				fdf->map->points[y][x].sx -= 2;
			if (ft_strnstr(buffer, "RIGHT", 5) != NULL)
				fdf->map->points[y][x].sx += 2;
			x++;
		}
		y++;
	}
}
