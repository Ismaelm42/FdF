/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_perspectives.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:40:28 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/22 11:40:49 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_point *point)
{
	int	x;
	int	y;

	x = point->sx;
	y = point->sy;
	point->sx = (x - y) * cos(0.52);
	point->sy = (x + y) * sin(0.52) - point->sz;
}

void	cavalier(t_point *point)
{
	int	x;
	int	y;

	x = point->sx;
	y = point->sy;
	point->sx = x + (point->sz * cos(0.52));
	point->sy = y + (point->sz * sin(0.52));
}
