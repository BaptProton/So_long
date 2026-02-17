/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:47:30 by proton            #+#    #+#             */
/*   Updated: 2024/04/04 16:22:38 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_map(t_map *map)
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
	map->move_player = 0;
}

static int	fill_map_struct(t_map *map)
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
				return (ft_putstr(SIZE_ERROR));
		}
		map->x = x;
	}
	map->y = y - 1;
	return (0);
}

static int	check_map_integrity(t_map *map)
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
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;

	if (argc == 2)
	{
		if (!check_name(argv[1]))
			return (ft_putstr(NAME_FILE));
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (ft_putstr(OPEN_FAULT));
		map.map = make_map(fd);
		if (!(map.map))
			return (1);
		initialize_map(&map);
		if (fill_map_struct(&map))
			return (free_board(map.map));
		if (check_map_integrity(&map))
			return (free_board(map.map));
		if (first_sort(&map))
			return (free_board(map.map));
		if (image_initialization(&map))
			return (free_board(map.map));
		free_board(map.map);
	}
	return (0);
}
