# include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_point	**points;

	if (argc <= 1 || argc > 2)
		return (0);
	map = map_size(argv[1], map);
	points = matrix_init(&map);
	points = coordinates_xy(&map, points);
	points = get_altitude_and_rgb(argv[1], &map, points);
	printf("map.w = %d\nmap.h = %d\n", map.width, map.height);
	printf("x = %d\ny = %d\n", points[9][9].x, points[9][9].y);
	return (0);
}
