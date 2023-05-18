/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:06:09 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/17 12:07:53 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*struct_init(t_map *map)
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
	fdf->w_height = HEIGHT;
	if (fdf->w_width / fdf->map->width < fdf->w_height / fdf->map->height)
		fdf->zoom = (fdf->w_width / fdf->map->width / 1.8);
	else
		fdf->zoom = (fdf->w_height / fdf->map->height / 1.8);
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
	return (fdf);
}

void	put_pixel(int pixel, t_point *point, t_fdf *fdf)
{
	fdf->mlx_image->pixels[pixel] = point->r;
	fdf->mlx_image->pixels[pixel + 1] = point->g;
	fdf->mlx_image->pixels[pixel + 2] = point->b;
	fdf->mlx_image->pixels[pixel + 3] = point->a;
}

t_coord	*bresenham_coord(t_point *a, t_point *b)
{
	t_coord	*coord;

	coord = (t_coord *)malloc(sizeof(t_coord));
	if (coord == NULL)
		error(ERR_MEM);
	coord->x = a->sx;
	coord->y = a->sy;
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

	coord = bresenham_coord(a, b);
	while (1)
	{
		pixel = (coord->x * 4) + (coord->y * fdf->mlx_image->width * 4);
		if ((coord->x < WIDTH && coord->x > 0)
			&& (coord->y < HEIGHT && coord->y > 0))
			put_pixel(pixel, a, fdf);
		if (coord->x == b->sx && coord->y == b->sy)
			break ;
		coord->err_2 = 2 * coord->err;
		if (coord->err_2 >= coord->dy)
		{
			coord->err = coord->err + coord->dy;
			coord->x = coord->x + coord->inc_x;
		}	
		if (coord->err_2 <= coord->dx)
		{
			coord->err = coord->err + coord->dx;
			coord->y = coord->y + coord->inc_y;
		}
	}
	free(coord);
}

void	draw(t_fdf *fdf)
{
	int		y;
	int		x;

	y = 0;
	ft_bzero(fdf->mlx_image->pixels, \
		sizeof(int) * fdf->mlx_image->width * fdf->mlx_image->height);
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				bresenham(&fdf->map->points[y][x], \
				&fdf->map->points[y][x + 1], fdf);
			if (y < fdf->map->height - 1)
				bresenham(&fdf->map->points[y][x], \
				&fdf->map->points[y + 1][x], fdf);
			x++;
		}
		y++;
	}
}
