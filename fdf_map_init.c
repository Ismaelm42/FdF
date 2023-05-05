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
	int		fd;
	int		width;
	int		height;
	char	*buffer;

	fd = open(argv, O_RDONLY);
	map = malloc(sizeof(t_map));
	if (fd == -1)
		error(ERR_OPEN);
	height = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL && height == 0)
			error(ERR_INPUT);
		if (buffer == NULL)
			break ;
		if (height == 0)
			width = ft_string_counter(buffer, 32);
		else if (height != 0 && width != ft_string_counter(buffer, 32))
			error(ERR_MAP_SIZE);
		height++;
	}
	map->height = height;
	map->width = width;
	return (close(fd), map);
}

t_point	**matrix_init(t_map *map)
{
	int		i;
	t_point	**points;

	i = 0;
	points = malloc(sizeof(t_point *) * map->width);
	while (i < map->width)
	{
		points[i] = malloc (sizeof(t_point) * map->height);
		i++;
	}
	return (points);
}

t_point	**coordinates_xy(t_map *map, t_point **points)
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
	return (points);
}

t_point	**get_altitude_and_rgb(char *argv, t_map *map, t_point **points)
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
			points[y][x].z = get_altitude(buffer[x]);
			get_rgb(&points[y][x], buffer[x]);
			printf("points->r = %d\n", points[y][x].r);
			printf("points->g = %d\n", points[y][x].g);
			printf("points->b = %d\n", points[y][x].b);
			x++;
		}
		y++;
	}
	free(buffer);
	return (close(fd), points);
}

int	get_altitude(char *buffer)
{
	int		len;

	if (ft_strchr(buffer, ',') == NULL)
		return (fdf_atoi(buffer));
	len = ft_strlen(buffer) - ft_strlen(ft_strchr(buffer, ','));
	return (fdf_atoi(ft_substr(buffer, 0, len)));
}

void	get_rgb(t_point *points, char *buffer)
{
	if (ft_strchr(buffer, ',') == NULL)
	{
		points->r = 19;
		points->g = 205;
		points->b = 231;
	}
	else
	{
		buffer = ft_strnstr(buffer, "0x", ft_strlen(buffer));
		if (ft_strlen(buffer) >= 4)
			points->r = hex_to_decimal(buffer, 2);
		if (ft_strlen(buffer) >= 6)
			points->g = hex_to_decimal(buffer, 4);
		if (ft_strlen(buffer) == 8)
			points->b = hex_to_decimal(buffer, 6);
		printf("points->r = %d\n", points->r);
		printf("points->g = %d\n", points->g);
		printf("points->b = %d\n", points->b);
	}
}
