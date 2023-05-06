# include "fdf.h"

void	error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(EXIT_FAILURE);
}
