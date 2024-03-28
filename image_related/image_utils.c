/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:54:55 by bproton           #+#    #+#             */
/*   Updated: 2024/03/28 18:24:11 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move_player(t_map *map, int move)
{
	if (move == W_KEY && map->map[map->y_pos - 1][map->x_pos] != '1')
	{
		map->map[map->y_pos][map->x_pos] = '0';
		map->map[map->y_pos - 1][map->x_pos] = 'P';
		map->y_pos -= 1;
		map_generation(map);
	}
	else if (move == S_KEY && map->map[map->y_pos + 1][map->x_pos] != '1')
	{
		map->map[map->y_pos][map->x_pos] = '0';
		map->map[map->y_pos + 1][map->x_pos] = 'P';
		map->y_pos += 1;
		map_generation(map);
	}
	else if (move == A_KEY && map->map[map->y_pos][map->x_pos - 1] != '1')
	{
		map->map[map->y_pos][map->x_pos] = '0';
		map->map[map->y_pos][map->x_pos - 1] = 'P';
		map->x_pos -= 1;
		map_generation(map);
	}
	else if (move == D_KEY && map->map[map->y_pos][map->x_pos + 1] != '1')
	{
		map->map[map->y_pos][map->x_pos] = '0';
		map->map[map->y_pos][map->x_pos + 1] = 'P';
		map->x_pos += 1;
		map_generation(map);
	}
}

int key_pressed(int keycode, t_map *map)
{
	(void)map;
	if (keycode == ESC_KEY)
		exit (0);
	if (keycode == W_KEY)
		move_player(map, keycode);
	else if (keycode == S_KEY)
		move_player(map, keycode);
	else if (keycode == A_KEY)
		move_player(map, keycode);
	else if (keycode == D_KEY)
		move_player(map, keycode);
	return (1);
}
