/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:30:45 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/12 11:57:53 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	put_pixel(int pixel, t_point *a, t_point *b, t_fdf *fdf)
{
	fdf->mlx_image->pixels[pixel] = a->r;
	fdf->mlx_image->pixels[pixel + 1] = a->g;
	fdf->mlx_image->pixels[pixel + 2] = a->b;
	fdf->mlx_image->pixels[pixel + 3] = a->a;
	b = (void *)b;
	// if (a->x == 1 && a->y == 0 && b->x == 1 && b->y == 1)
	// {
	// 	printf("a->x = %d\t| a->y = %d\n", a->x, a->y);
	// 	printf("b->x = %d\t| b->y = %d\n", b->x, b->y);
	// 	printf("a->sx = %d\t| a->sy = %d\n", a->sx, a->sy);
	// 	printf("b->sx = %d\t| b->sy = %d\n", b->sx, b->sy);
	// }
}
