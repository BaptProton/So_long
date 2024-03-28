/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:47:30 by proton            #+#    #+#             */
/*   Updated: 2024/03/27 17:44:23 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void initialize_map(t_map *map)
{
	map->img_h = 0;
	map->img_w = 0;
	map->coins = 0;
	map->player = 0;
	map->exit = 0;
	map->x = 0;
	map->y = 0;
	map->x_pos = 0;
	map->y_pos = 0;
	map->y_new = -1;
}

static int fill_map_struct(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (map->map[++y] != NULL)
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == 'P')
				map->player += 1;
			else if (map->map[y][x] == 'C')
				map->coins += 1;
			else if (map->map[y][x] == 'E')
				map->exit += 1;
		}
		if (map->x != 0)
		{
			if (map->x < x || map->x > x)
				return (SIZE_ERROR);
		}
		map->x = x;
	}
	map->y = y - 1;
	return (0);
}

static int check_map_integrity(t_map *map)
{
	if (check_map_basics(map))
		return (1);
	if (check_first_last_row(map->y, map))
		return (1);
	if (check_middle_map_walls(map))
		return (1);
	if (check_other_char(map))
		return (1);
	return (0);
}

static char	**make_map(int fd)
{
	char	**map;
	char	*temp;
	int		check;
	
	temp = malloc(sizeof(char) * BUFFER_SIZE);
	if (!temp)
		return (NULL);
	check = read(fd, temp, BUFFER_SIZE);
	if (check < 0)
	{
		free(temp);
		return (NULL);
	}
	temp[check] = '\0';
	map = ft_split(temp, '\n');
	free(temp);
	return (map);
}

int main(int argc, char **argv)
{
	t_map	map;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(map.map = make_map(fd)) && map.map)
			return (free_board(map.map, fd));
		initialize_map(&map);
		if (fill_map_struct(&map))
			return (free_board(map.map, fd));
			printf("x value %d\n", map.x);
			printf("y value %d\n", map.y);
		if (check_map_integrity(&map))
			return (free_board(map.map, fd));
			printf("x value %d\n", map.x);
			printf("y value %d\n", map.y);
		if (first_sort(&map))
			return (free_board(map.map, fd));
			printf("x value %d\n", map.x);
			printf("y value %d\n", map.y);
		if (image_initialization(&map))
			return (free_board(map.map, fd));
			printf("x value %d\n", map.x);
			printf("y value %d\n", map.y);
		free_board(map.map, fd);
	}
	return (0);
}
