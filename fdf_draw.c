# include "fdf.h"

t_fdf	*map_init(t_map *map)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		error(ERR_MEM);
	fdf->map = map;
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!fdf->mlx)
		error(ERR_MLX);
	fdf->w_width = WIDTH;
	fdf->w_heigth = HEIGHT;
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
	int		pixel;

	coord = coord_init(a, b);
	while (1)
	{
		pixel = (a->sx * 4) + (a->sy * fdf->mlx_image->width * 4);
		if (a->sx < fdf->w_width && a->sy < fdf->w_heigth)
			put_pixel(pixel, a, b, fdf);
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
	draw_while(fdf);
}
