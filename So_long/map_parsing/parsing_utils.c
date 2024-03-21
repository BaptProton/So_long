/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:02:24 by bproton           #+#    #+#             */
/*   Updated: 2024/03/15 17:28:43 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_map_basics(t_map *map)
{
    if (map->player != 1)
        return (PLAYER_ERROR);
    if (map->coins < 1)
        return (COIN_ERROR);
    if (map->exit != 1)
        return (EXIT_ERROR);
    
    return (0);
}

int	check_first_last_row(int y, t_map *map)
{
	int	x;

    x = -1;
    while (++x < map->x)
    {
		if (map->map[0][x] != '1')
			return (TOP_BOT_WALL_ERROR);
        if (map->map[y][x] != '1')
            return (TOP_BOT_WALL_ERROR);
    }
	return (0);
}

int check_middle_map_walls(t_map *map)
{
    int y;
    int x;

    y = 0;
    while (++y != map->y)
    {
        x = -1;
        while (map->map[y][++x])
        {
            if (map->map[y][x] == 'C')
            {
                if (map->map[y -1][x] == '1' && map->map[y + 1][x] == '1' 
                    && map->map[y][x - 1] == '1' && map->map[y][x + 1] == '1')
                        return (COIN_ERROR);
            }
        }
        if (map->map[y][0] != '1' || map->map[y][map->x -1] != '1')
            return (SIDE_WALL_ERROR);
    }
    return (0);
}

int check_other_char(t_map *map)
{
    int x;
    int y;

    y = -1;
    while (++y < map->y)
    {
        x = -1;
        while (map->map[y][++x] != '\0')
        {
           if (map->map[y][x] != '1' && map->map[y][x] != '0'
                && map->map[y][x] != 'P' && map->map[y][x] != 'C'
                    && map->map[y][x] != 'E')
                return (NOT_RECO_ERROR);
            if (map->map[y][x] == 'P')
            {
                map->x_pos = x;
                map->y_pos = y;
            }
        }
    }
    return (0);
}