/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:47:24 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/12 15:22:46 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

t_map	*map_size(char *argv)
{
	t_map	*map;
	char	*buffer;
	int		fd;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		error(ERR_MEM);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error(ERR_OPEN);
	map->height = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL && map->height == 0)
			error(ERR_INPUT);
		if (buffer == NULL)
			break ;
		if (map->height == 0)
			map->width = wrd_counter(buffer, 32);
		else if (map->height != 0 && map->width != wrd_counter(buffer, 32))
			error(ERR_MAP_SIZE);
		map->height++;
		free(buffer);
	}
	return (close(fd), map);
}

void	map_init(t_map *map)
{
	int		i;

	i = 0;
	map->points = (t_point **)malloc(sizeof(t_point *) * map->height);
	if (map->points == NULL)
		error(ERR_MEM);
	while (i < map->height)
	{
		map->points[i] = malloc (sizeof(t_point) * map->width);
		if (map->points[i] == NULL)
			error(ERR_MEM);
		i++;
	}
}

void	coordinates_xyz(char *argv, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->points[y][x].x = x;
			map->points[y][x].y = y;
			x++;
		}
		y++;
	}
	get_altitude_and_rgb(argv, map);
}

void	get_altitude_and_rgb(char *argv, t_map *map)
{
	char	**buffer;
	int		x;
	int		y;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error(ERR_OPEN);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		buffer = ft_split(get_next_line(fd), 32);
		if (buffer == NULL)
			error(ERR_OPEN);
		while (x < map->width)
		{
			get_altitude(&map->points[y][x], buffer[x]);
			get_rgb(&map->points[y][x], buffer[x]);
			x++;
		}
		y++;
		split_free(buffer);
	}
	close(fd);
}
