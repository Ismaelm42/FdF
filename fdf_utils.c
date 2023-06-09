/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:31:09 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/22 11:40:01 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(EXIT_FAILURE);
}

int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void	split_free(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != NULL)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

void	matrix_free(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->map->height)
	{
		free(fdf->map->points[i]);
		i++;
	}
	free(fdf->map->points);
	free(fdf->map);
	free(fdf);
}

void	set_array(int *array, int nbr, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		array[i] = nbr;
		i++;
	}
}
