/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:46:23 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/12 17:21:57 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_fdf	*fdf;

	//leaks
	atexit(ft_leaks);

	//parse
	if (argc <= 1 || argc > 2)
		return (0);
	map = map_size(argv[1]);
	map_init(map);
	coordinates_xyz(argv[1], map);

	//mlx_init
	fdf = struct_init(map);

	//create_window
	fdf->mlx_image = mlx_new_image(fdf->mlx, fdf->w_width, fdf->w_heigth);
	if (!fdf->mlx)
		error(ERR_MLX);
	if (mlx_image_to_window(fdf->mlx, fdf->mlx_image, WIDTH / 5 * 1.5, HEIGHT / 4) == -1)
		error(ERR_MLX);

	//perspective
	perspective(fdf);

	//draw
	draw(fdf);

	//mlx_menu
	//menu(fdf);

	//mlx_loop
	mlx_loop(fdf->mlx);

	//mlx_terminate
	mlx_delete_image(fdf->mlx, fdf->mlx_image);
	mlx_terminate(fdf->mlx);

	//matrix_free(fdf);
	matrix_free(fdf);
	return (0);
}













































void	printing_matrix(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (fdf->map->points[y][x].z == 0)
				printf(" ");
			printf("%d ", fdf->map->points[y][x].z);
			x++;
		}
		printf("\n");
		y++;
	}
}
