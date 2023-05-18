/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_viewpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:05:10 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/17 13:06:02 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_fdf *fdf)
{
	int	x;
	int	y;

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
			if (fdf->viewpoint == 1)
				cavalier(&fdf->map->points[y][x]);
			else
				isometric(&fdf->map->points[y][x]);
			x++;
		}
		y++;
	}
}

void	focus(t_fdf *fdf)
{
	int	x;
	int	y;
	int	*min;

	y = 0;
	min = get_minimum(fdf);
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			fdf->map->points[y][x].sx -= min[0];
			fdf->map->points[y][x].sy -= min[1];
			fdf->map->points[y][x].sx += (fdf->w_width / 4) - (fdf->map->width * fdf->zoom / 4);
			fdf->map->points[y][x].sy += (fdf->w_heigth / 4) - (fdf->map->height * fdf->zoom / 4);
			x++;
		}
		y++;
	}
	free(min);
}
