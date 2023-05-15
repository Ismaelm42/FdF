# include "fdf.h"

void	hooks(void *struc)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)struc;
	close_window(fdf);
	//new_view;
	make_rotation(fdf);
	make_translation(fdf);
	make_zoom(fdf);
}

void	close_window(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
}

void	make_rotation(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
	{
		fdf->alpha -= 0.007;
		perspective(fdf);
		focus(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
	{
		fdf->alpha += 0.007;
		perspective(fdf);
		focus(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
	{
		fdf->beta += 0.007;
		perspective(fdf);
		focus(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
	{
		fdf->beta -= 0.007;
		perspective(fdf);
		focus(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
	{
		fdf->gamma += 0.007;
		perspective(fdf);
		focus(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
	{
		fdf->gamma -= 0.007;
		perspective(fdf);
		focus(fdf);
		draw(fdf);
	}

}

void	make_translation(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
	{
		translate(fdf, "UP");
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		translate(fdf, "DOWN");
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		translate(fdf, "LEFT");
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		translate(fdf, "RIGHT");
}

void	make_zoom(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT_CONTROL))
	{
		fdf->zoom += 3;
		perspective(fdf);
		draw(fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT_ALT))
	{
		fdf->zoom -= 4;
		perspective(fdf);
		draw(fdf);
	}
}
