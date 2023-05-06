/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:47:24 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/05 13:47:27 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

t_map	*map_size(char *argv)
{
	t_map	*map;
	char	*buffer;
	int		fd;

	map = malloc(sizeof(t_map));
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
			map->width = ft_str_counter(buffer, 32);
		else if (map->height != 0 && map->width != ft_str_counter(buffer, 32))
			error(ERR_MAP_SIZE);
		map->height++;
	}
	return (close(fd), map);
}

t_point	**matrix_init(t_map *map)
{
	int		i;
	t_point	**points;

	i = 0;
	points = malloc(sizeof(t_point *) * map->width);
	if (points == NULL)
		error(ERR_MEM);
	while (i < map->width)
	{
		points[i] = malloc (sizeof(t_point) * map->height);
		if (points[i] == NULL)
			error(ERR_MEM);
		i++;
	}
	return (points);
}

void	coordinates_xy(t_map *map, t_point **points)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			points[y][x].x = x;
			points[y][x].y = y;
			x++;
		}
		y++;
	}
}

void	get_altitude_and_rgb(char *argv, t_map *map, t_point **points)
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
			get_altitude(&points[y][x], buffer[x]);
			get_rgb(&points[y][x], buffer[x]);
			x++;
		}
		y++;
	}
	free(buffer);
	close(fd);
}

