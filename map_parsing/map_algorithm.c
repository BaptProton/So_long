/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:35:20 by proton            #+#    #+#             */
/*   Updated: 2024/04/03 19:02:27 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_safe(t_map *map, int x, int y)
{
	if (y > map->y)
		return (0);
	else if (x > map->x)
		return (0);
	else if (x < 0)
		return (0);
	else if (y < 0)
		return (0);
	return (1);
}

char	**clone_map(t_map *map)
{
	int		y;
	int		x;
	char	**clone;

	clone = (char **)malloc(sizeof(char *) * (map->y + 2));
	if (!clone)
		return (NULL);
	y = -1;
	while (++y <= map->y)
	{
		clone[y] = (char *)malloc(sizeof(char) * map->x);
		if (!clone[y])
		{
			free_board(clone, 0);
			return (NULL);
		}
		x = -1;
		while (++x < map->x)
			clone[y][x] = map->map[y][x];
		clone[y][x] = '\0';
	}
	clone[y] = NULL;
	return (clone);
}

int	search_recursive(t_map *map, char **clone, int x, int y)
{
	static int	find_exit = 0;
	static int	num_coins = 0;

	if (is_safe(map, x, y) && clone[y][x] != '1')
	{
		if (clone[y][x] == 'E')
			find_exit = 1;
		if (clone[y][x] == 'C')
			num_coins += 1;
		clone[y][x] = '1';
		if ((search_recursive(map, clone, x, (y - 1))))
			return (1);
		if ((search_recursive(map, clone, x, (y + 1))))
			return (1);
		if ((search_recursive(map, clone, (x + 1), y)))
			return (1);
		if ((search_recursive(map, clone, (x - 1), y)))
			return (1);
		if (num_coins == map->coins && find_exit == 1)
			return (1);
	}
	return (0);
}

int	first_sort(t_map *map)
{
	char	**clone;
	int		x;
	int		y;

	y = -1;
	clone = clone_map(map);
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (map->map[y][x] == 'P')
			{
				if (!search_recursive(map, clone, x, y))
				{
					free_board(clone, 0);
					return (MAP_ERROR);
				}
			}
		}
	}
	free_board(clone, 0);
	return (0);
}
