/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:35:20 by proton            #+#    #+#             */
/*   Updated: 2024/03/21 18:05:27 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_safe(t_map *map, int x, int y)
{
	if (y >= map->y)
		return (0);
	else if (x > map->x)
		return (0);
    else if (map->map[y][x +1] == '1' && map->map[y][x -1] == '1' 
            && map->map[y +1][x] == '1' && map->map[y -1][x] == '1')
            return (0);
	return (1);
}

int	recursive_search(t_map *map, int **clone, int x, int y)
{
	static int	find_exit = 0;
	static int	num_coins = 0;

	if (is_safe(map, x, y) && map->map[y][x] != '1' && clone[y][x] != 1)
	{
		if (map->map[y][x] == 'E')
			find_exit = 1;
		if (clone[y][x] == 2)
			num_coins += 1;
		clone[y][x] = 1;
		if ((recursive_search(map, clone, x, (y - 1))))
			return (1);
		if ((recursive_search(map, clone, x, (y + 1))))
			return (1);
		if ((recursive_search(map, clone, (x + 1), y)))
			return (1);
		if ((recursive_search(map, clone, (x - 1), y)))
			return (1);
		if (num_coins == map->coins && find_exit == 1)
			return (1);
	}
	return (0);
}

int	**clone_arrays(t_map *map)
{
	int	**clone;
	int	x;
	int	y;

	clone = (int **)malloc(sizeof(int *) * map->y);
	if (!clone)
		return (NULL);
	y = -1;
	while (++y < map->y)
	{
		clone[y] = (int *)malloc(sizeof(int) * map->x);
		if (!clone)
			return (NULL);
		x = -1;
		while (++x < map->x)
		{
			if (map->map[y][x] == '1')
				clone[y][x] = 1;
            else if (map->map[y][x] == 'C')
				clone[y][x] = 2;
			else
				clone[y][x] = 0;
		}
	}
	return (clone);
}

int	first_sort(t_map *map)
{
	int	**clone;
	int	x;
	int	y;

	if (!(clone = clone_arrays(map)))
		return (1);
	y = -1;		
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (map->map[y][x] == 'P')
				if (!recursive_search(map, clone, x, y))
					return (MAP_ERROR);
		}
	}
	return (0);
}

