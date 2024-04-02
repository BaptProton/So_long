/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:28:10 by bproton           #+#    #+#             */
/*   Updated: 2024/04/02 16:08:25 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player_negativ_x(t_map *map, int move)
{
	if (move == A_KEY && map->map[map->y_pos][map->x_pos - 1] != '1')
	{
		if (map->map[map->y_pos][map->x_pos - 1] == 'C')
		{
			map->coins -= 1;
			map->map[map->y_pos][map->x_pos - 1] = '0';
		}
		replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 1);
		map->x_pos -= 1;
		replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 2);
		if (map->map[map->y_pos][map->x_pos] == 'E' && map->coins == 0)
			close_window(move, map);
	}
}

void	move_player_positiv_x(t_map *map, int move)
{
	if (move == D_KEY && map->map[map->y_pos][map->x_pos + 1] != '1')
	{
		if (map->map[map->y_pos][map->x_pos + 1] == 'C')
		{
			map->coins -= 1;
			map->map[map->y_pos][map->x_pos + 1] = '0';
		}
		replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 1);
		map->x_pos += 1;
		replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 2);
		if (map->map[map->y_pos][map->x_pos] == 'E' && map->coins == 0)
			close_window(move, map);
	}
}

void	move_player_negativ_y(t_map *map, int move)
{
	if (move == W_KEY && map->map[map->y_pos - 1][map->x_pos] != '1')
	{
		if (map->map[map->y_pos - 1][map->x_pos] == 'C')
		{
			map->coins -= 1;
			map->map[map->y_pos - 1][map->x_pos] = '0';
		}
		replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 1);
		map->y_pos -= 1;
		replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 2);
		if (map->map[map->y_pos][map->x_pos] == 'E' && map->coins == 0)
			close_window(move, map);
	}
}

void	move_player_positiv_y(t_map *map, int move)
{
	if (move == S_KEY && map->map[map->y_pos + 1][map->x_pos] != '1')
	{
		if (map->map[map->y_pos + 1][map->x_pos] == 'C')
		{
			map->coins -= 1;
			map->map[map->y_pos + 1][map->x_pos] = '0';
		}
		replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 1);
		map->y_pos += 1;
		replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 2);
		if (map->map[map->y_pos][map->x_pos] == 'E' && map->coins == 0)
			close_window(move, map);
	}
}
