/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:35:20 by proton            #+#    #+#             */
/*   Updated: 2024/04/02 15:23:02 by bproton          ###   ########.fr       */
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
    // if (map->map[y][x +1] == '1' && map->map[y][x -1] == '1' 
    //         && map->map[y +1][x] == '1' && map->map[y -1][x] == '1')
            // return (0);
	return (1);
}

// int	recursive_search(t_map *map, int **clone, int x, int y)
// {
// 	static int	find_exit = 0;
// 	static int	num_coins = 0;

// 	if (is_safe(map, x, y) && map->map[y][x] != '1' && clone[y][x] != 1)
// 	{
// 		if (map->map[y][x] == 'E')
// 			find_exit = 1;
// 		if (clone[y][x] == 2)
// 			num_coins += 1;
// 		clone[y][x] = 1;
// 		if ((recursive_search(map, clone, x, (y - 1))))
// 			return (1);
// 		if ((recursive_search(map, clone, x, (y + 1))))
// 			return (1);
// 		if ((recursive_search(map, clone, (x + 1), y)))
// 			return (1);
// 		if ((recursive_search(map, clone, (x - 1), y)))
// 			return (1);
// 		if (num_coins == map->coins && find_exit == 1)
// 			return (1);
// 	}
// 	return (0);
// }

// int	**clone_arrays(t_map *map)
// {
// 	int	**clone;
// 	int	x;
// 	int	y;

// 	clone = (int **)malloc(sizeof(int *) * map->y + 1);
// 	if (!clone)
// 		return (NULL);
// 	y = -1;
// 	while (++y <= map->y)
// 	{
// 		clone[y] = (int *)malloc(sizeof(int) * map->x);
// 		if (!clone)
// 			return (NULL);
// 		x = -1;
// 		while (++x < map->x)
// 		{
// 			if (map->map[y][x] == '1')
// 				clone[y][x] = 1;
//             else if (map->map[y][x] == 'C')
// 				clone[y][x] = 2;
// 			else
// 				clone[y][x] = 0;
// 			printf("%p\n", &clone[y][x]);
// 		}
// 	}
// 	return (clone);
// }

char	**clone_map(t_map *map)
{
	int		y;
	int		x;
	char	**clone;

	clone = (char **)malloc(sizeof(char *) * map->y + 1);
	if (!clone)
		return (NULL);
	y = -1;
	while (++y <= map->y)
	{
		clone[y] = (char *)malloc(sizeof(char) * map->x);
		if (!clone[y])
			return (NULL);
		x = -1;
		while (++x < map->x)
			clone[y][x] = map->map[y][x];
		clone[y][x] = '\0';
	}
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
	// int	**clone;
	char	**clone;
	int		x;
	int		y;

	// if (!(clone = clone_arrays(map)))
	// 	return (1);
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
				// if (!recursive_search(map, clone, x, y))
				// {
				// 	free_int_board(clone, map);
				// 	return (MAP_ERROR);
				// }
		}
	}
	free_board(clone, 0);
	return (0);
}

