# include "fdf.h"

int	elts_counter(char *buffer)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] != 32 && (buffer[i + 1] == 32 || buffer[i + 1] == '\0'))
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

t_map	map_file_check(char *argv, t_map map)
{
	int		fd;
	int		width;
	int		height;
	char	*buffer;

	fd = open(argv, O_RDONLY);
	height = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL && height == 0)
			error(ERR_INPUT);
		if (buffer == NULL)
			break ;
		if (height == 0)
			width = elts_counter(buffer);
		else if (height != 0 && width != elts_counter(buffer))
			error(ERR_MAP_SIZE);
		height++;
	}
	map.height = height;
	map.width = width;
	map.size = height * width;
	return (map);
}


