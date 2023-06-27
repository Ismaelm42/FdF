/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:48:17 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/22 13:26:59 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_rotation_x(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
	{
		fdf->alpha -= 0.007;
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
		focus(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
	{
		fdf->alpha += 0.007;
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
		focus(fdf);
		draw(fdf);
	}
}

void	do_rotation_y(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
	{
		fdf->beta += 0.007;
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
		focus(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
	{
		fdf->beta -= 0.007;
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
		focus(fdf);
		draw(fdf);
	}
}

void	do_rotation_z(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
	{
		fdf->gamma += 0.007;
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
		focus(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
	{
		fdf->gamma -= 0.007;
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
		focus(fdf);
		draw(fdf);
	}
}

void	do_inc_z(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Z))
	{
		inc_z(fdf, "ADD");
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
		focus(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_X))
	{
		inc_z(fdf, "SUBSTRACT");
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
		focus(fdf);
		draw(fdf);
	}
}
