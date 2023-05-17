/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_viewpoint_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:05:18 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/17 12:07:41 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*get_minimum(t_fdf *fdf)
{
	int	x;
	int	y;
	int	*min;

	y = 0;
	min = (int *)malloc(sizeof(int) * 2);
	min[0] = fdf->map->points[0][0].sx;
	min[1] = fdf->map->points[0][0].sy;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (fdf->map->points[y][x].sx < min[0])
				min[0] = fdf->map->points[y][x].sx;
			if (fdf->map->points[y][x].sy < min[1])
				min[1] = fdf->map->points[y][x].sy;
			x++;
		}
		y++;
	}
	return (min);
}

void	rotate_x(t_point *point, t_fdf *fdf)
{
	point->sy = point->sy * cos(fdf->alpha) + point->sz * sin(fdf->alpha);
	point->sz = -point->sy * sin(fdf->alpha) + point->sz * cos(fdf->alpha);
}

void	rotate_y(t_point *point, t_fdf *fdf)
{
	point->sx = point->sx * cos(fdf->beta) + point->sz * sin(fdf->beta);
	point->sz = -point->sx * sin(fdf->beta) + point->sz * cos(fdf->beta);
}

void	rotate_z(t_point *point, t_fdf *fdf)
{
	point->sx = point->sx * cos(fdf->gamma) - point->sy * sin(fdf->gamma);
	point->sy = point->sx * sin(fdf->gamma) + point->sy * cos(fdf->gamma);
}

void	isometric(t_point *point)
{
	int	x;
	int	y;

	x = point->sx;
	y = point->sy;
	point->sx = (x - y) * cos(0.52);
	point->sy = (x + y) * sin(0.52) - point->sz;
}
