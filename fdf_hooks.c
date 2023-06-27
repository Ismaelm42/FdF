/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:05:54 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/22 12:39:54 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hooks(void *struc)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)struc;
	close_window(fdf);
	select_viewpoint(fdf);
	do_rotation_x(fdf);
	do_rotation_y(fdf);
	do_rotation_z(fdf);
	do_translation(fdf);
	do_zoom(fdf);
	do_inc_z(fdf);
}

void	close_window(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
}

void	select_viewpoint(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
	{
		fdf->viewpoint = 0;
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
		focus(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_C))
	{
		fdf->viewpoint = 1;
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
		focus(fdf);
		draw(fdf);
	}
}

void	do_translation(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
	{
		translate(fdf, "UP");
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
	{
		translate(fdf, "DOWN");
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
	{
		translate(fdf, "LEFT");
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
	{
		translate(fdf, "RIGHT");
		draw(fdf);
	}
}

void	do_zoom(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
	{
		fdf->zoom += 1;
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
		focus(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
	{
		if (fdf->zoom > 0)
		{
			fdf->zoom -= 1;
			zoom(fdf);
			rotation(fdf);
			viewpoint(fdf);
			focus(fdf);
			draw(fdf);
		}
	}
}
