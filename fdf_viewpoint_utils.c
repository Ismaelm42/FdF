/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_viewpoint_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:05:18 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/22 11:40:23 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_min_and_max(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	fdf->min_and_max = (int *)malloc(sizeof(int) * 4);
	set_array(fdf->min_and_max, 0, 4);
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (fdf->map->points[y][x].sx < fdf->min_and_max[0])
				fdf->min_and_max[0] = fdf->map->points[y][x].sx;
			if (fdf->map->points[y][x].sy < fdf->min_and_max[1])
				fdf->min_and_max[1] = fdf->map->points[y][x].sy;
			if (fdf->map->points[y][x].sx > fdf->min_and_max[2])
				fdf->min_and_max[2] = fdf->map->points[y][x].sx;
			if (fdf->map->points[y][x].sy > fdf->min_and_max[3])
				fdf->min_and_max[3] = fdf->map->points[y][x].sy;
			x++;
		}
		y++;
	}
	fdf->min_and_max[2] -= fdf->min_and_max[0];
	fdf->min_and_max[3] -= fdf->min_and_max[1];
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
