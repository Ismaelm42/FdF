/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:31:09 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/12 11:31:10 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	ft_leaks(void)
{
	system ("leaks -q fdf");
}

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

void	swap(t_point *point)
{
	int	a;

	a = point->sx;
	point->sx = point->sy;
	point->sy = a;
}
