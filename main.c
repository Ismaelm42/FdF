/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:46:23 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/17 12:12:23 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_fdf	*fdf;

	atexit(ft_leaks);

	if (argc <= 1 || argc > 2)
		return (0);
	map = map_size(argv[1]);
	map_init(map);
	coordinates_xyz(argv[1], map);

	fdf = struct_init(map);


	fdf->mlx_image = mlx_new_image(fdf->mlx, fdf->w_width, fdf->w_height);
	if (!fdf->mlx_image)
		error(ERR_MLX);
	if (mlx_image_to_window(fdf->mlx, fdf->mlx_image, 0, 0) == -1)
		error(ERR_MLX);
		
	zoom(fdf);
	rotation(fdf);
	viewpoint(fdf);
	focus(fdf);

	draw(fdf);

	mlx_loop_hook(fdf->mlx, &hooks, (void *)fdf);

	mlx_loop(fdf->mlx);

	mlx_delete_image(fdf->mlx, fdf->mlx_image);
	mlx_terminate(fdf->mlx);

	matrix_free(fdf);
	return (0);
}
