# include "fdf.h"

void	menu(t_fdf *fdf)
{
	fdf->mlx_image = mlx_new_image(fdf->mlx, fdf->w_width / 5, fdf->w_heigth);
	if (!fdf->mlx)
		error(ERR_MLX);
	if (mlx_image_to_window(fdf->mlx, fdf->mlx_image, 0, 0) == -1)
		error(ERR_MLX);
}
