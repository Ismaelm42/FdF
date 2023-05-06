/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:46:23 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/05 13:46:26 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_point	**points;

	if (argc <= 1 || argc > 2)
		return (0);
	map = map_size(argv[1]);
	points = matrix_init(map);
	coordinates_xy(map, points);
	get_altitude_and_rgb(argv[1], map, points);
	return (0);
}
