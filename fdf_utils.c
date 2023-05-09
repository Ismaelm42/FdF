# include "fdf.h"

void	ft_leaks(void)
{
	system ("leaks -q fdf");
}

void	error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(EXIT_FAILURE);
}

int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void	swap(int *x, int *y)
{
	int	*a;

	a = x;
	x = y;
	y = a;
}
