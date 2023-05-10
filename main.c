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
	t_fdf	*fdf;

	//leaks
	atexit(ft_leaks);

	//parse
	if (argc <= 1 || argc > 2)
		return (0);
	map = map_size(argv[1]);
	matrix_init(map);
	coordinates_xyz(argv[1], map);

	//mlx_init
	fdf = map_init(map);
	fdf->mlx_image = mlx_new_image(fdf->mlx, fdf->w_width, fdf->w_heigth);

	if (!fdf->mlx)
		error(ERR_MLX);
	if (mlx_image_to_window(fdf->mlx, fdf->mlx_image, 0, 0) < 0)
		error(ERR_MLX);

	//focus
	focus(fdf);
	printf("width = %d\n", fdf->map->width);
	printf("height = %d\n", fdf->map->height);

	//draw
	draw(fdf);

	//bresenham_test
	// t_point *a;
	// t_point *b;
	// a = &fdf->map->points[0][0];
	// b = &fdf->map->points[10][18];
	// bresenham(a, b, fdf);

	//mlx loop
	mlx_loop(fdf->mlx);

	//mlx_terminate
	mlx_delete_image(fdf->mlx, fdf->mlx_image);
	mlx_terminate(fdf->mlx);
	return (0);
}







// int	compare(int a, int b)
// {
// 	int	ret;

// 	if (a < b)
// 		ret = 1;
// 	else
// 		ret = -1;
// 	return (ret);
// }

// t_param	*init_param(t_point *a, t_point *b)
// {
// 	t_param	*param;

// 	param = (t_param *)malloc(sizeof(t_param));
// 	if (!param)
// 		return (NULL);
// 	param->dx = abs(b->x - a->x);
// 	param->sx = compare(a->x, b->x);
// 	param->dy = -abs(b->y - a->y);
// 	param->sy = compare(a->y, b->y);
// 	param->err = param->dx + param->dy;
// 	return (param);
// }

// void	bresenham(t_fdf *fdf, t_point *a, t_point *b)
// {
// 	t_param	*param;

// 	param = init_param(a, b);
// 	while (1)
// 	{
// 		put_pixel(fdf, a->x, a->y);
// 		if (a->x == b->x && a->y == b->y)
// 			break ;
// 		param->e2 = 2 * param->err;
// 		if (param->e2 >= param->dy)
// 		{
// 			param->err += param->dy;
// 			a->x += param->sx;
// 		}	
// 		if (param->e2 <= param->dx)
// 		{
// 			param->err += param->dx;
// 			a->y += param->sy;
// 		}
// 	}
// 	free(a);
// 	free(b);
// 	free(param);
// }












































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
