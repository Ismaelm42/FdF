# include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_map	*map_pointer;
	t_point	p;

	if (argc <= 1 || argc > 2)
		return (0);
	map = map_file_check(argv[1], map);
	map_pointer = &map;
	p = init_point(p, argv[1], *map_pointer);
	return (0);
}
