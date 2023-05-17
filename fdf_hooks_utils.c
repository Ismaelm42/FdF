/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:06:00 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/17 12:07:51 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

