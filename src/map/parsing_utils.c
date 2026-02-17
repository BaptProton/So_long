/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:02:24 by bproton           #+#    #+#             */
/*   Updated: 2026/02/17 12:10:25 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_map_basics(t_map *map)
{
	if (map->player != 1)
		return (ft_putstr(PLAYER_ERROR));
	if (map->coins < 1)
		return (ft_putstr(COIN_ERROR));
	if (map->exit != 1)
		return (ft_putstr(EXIT_ERROR));
	return (0);
}

int	check_first_last_row(int y, t_map *map)
{
	int	x;

	x = -1;
	while (++x < map->x)
	{
		if (map->map[0][x] != '1')
			return (ft_putstr(TOP_BOT_WALL_ERROR));
		if (map->map[y][x] != '1')
			return (ft_putstr(TOP_BOT_WALL_ERROR));
	}
	return (0);
}

int	check_middle_map_walls(t_map *map)
{
	int	y;

	y = 0;
	while (++y != map->y)
	{
		if (map->map[y][0] != '1' || map->map[y][map->x -1] != '1')
			return (ft_putstr(SIDE_WALL_ERROR));
	}
	return (0);
}

int	check_other_char(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (map->map[y][++x] != '\0')
		{
			if (map->map[y][x] != '1' && map->map[y][x] != '0'
					&& map->map[y][x] != 'P' && map->map[y][x] != 'C'
						&& map->map[y][x] != 'E')
				return (ft_putstr(NOT_RECO_ERROR));
			if (map->map[y][x] == 'P')
			{
				map->x_pos = x;
				map->y_pos = y;
			}
		}
	}
	return (0);
}
