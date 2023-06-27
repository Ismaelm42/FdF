/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:06:00 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/22 13:10:12 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	re_draw(t_fdf *fdf)
{
	zoom(fdf);
	rotation(fdf);
	viewpoint(fdf);
	focus(fdf);
	draw(fdf);
}

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
				fdf->map->points[y][x].sy -= 5;
			if (ft_strnstr(buffer, "DOWN", 4) != NULL)
				fdf->map->points[y][x].sy += 5;
			if (ft_strnstr(buffer, "LEFT", 4) != NULL)
				fdf->map->points[y][x].sx -= 5;
			if (ft_strnstr(buffer, "RIGHT", 5) != NULL)
				fdf->map->points[y][x].sx += 5;
			x++;
		}
		y++;
	}
}

void	inc_z(t_fdf *fdf, char *buffer)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (ft_strnstr(buffer, "ADD", 3) != NULL)
				if (fdf->map->points[y][x].z != 0)
						fdf->map->points[y][x].z += 1;
			if (ft_strnstr(buffer, "SUBSTRACT", 9) != NULL)
				if (fdf->map->points[y][x].z != 0)
						fdf->map->points[y][x].z -= 1;
			x++;
		}
		y++;
	}
}
