# include "fdf.h"

void	hooks(void *struc)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)struc;
	close_window(fdf);
	do_translation(fdf);
	do_rotation_xy(fdf);
	do_rotation_z(fdf);
	do_zoom(fdf);
}

void	close_window(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
}

void	do_rotation_xy(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
	{
		fdf->alpha -= 0.007;
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
	{
		fdf->alpha += 0.007;
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
	{
		fdf->beta += 0.007;
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
	{
		fdf->beta -= 0.007;
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
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
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
	{
		fdf->gamma -= 0.007;
		zoom(fdf);
		rotation(fdf);
		viewpoint(fdf);
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
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT_CONTROL))
	{
		//zoom(fdf, 0, 0);
		fdf->zoom *= 1.1;
		rotation(fdf);
		//viewpoint(fdf, 1);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT_ALT))
	{
		//zoom(fdf, 0, 0);
		fdf->zoom *= 0.9;
		rotation(fdf);
		//viewpoint(fdf, 1);
		draw(fdf);
	}
}
