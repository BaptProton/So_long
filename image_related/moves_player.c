/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:28:10 by bproton           #+#    #+#             */
/*   Updated: 2024/04/02 17:51:41 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player_negativ_x(t_map *map, int move)
{
	if (move == A_KEY && map->map[map->y_pos][map->x_pos - 1] != '1')
	{
		printf("%d\n", ++map->move_player);
		if (map->map[map->y_pos][map->x_pos - 1] == 'C')
		{
			map->coins -= 1;
			map->map[map->y_pos][map->x_pos - 1] = '0';
		}
		replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 1);
		if (map->map[map->y_pos][map->x_pos] == 'E')
			replace_if_exit(map, map->y_pos * 32, map->x_pos * 32);
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
		printf("%d\n", ++map->move_player);
		if (map->map[map->y_pos][map->x_pos + 1] == 'C')
		{
			map->coins -= 1;
			map->map[map->y_pos][map->x_pos + 1] = '0';
		}
		replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 1);
		if (map->map[map->y_pos][map->x_pos] == 'E')
			replace_if_exit(map, map->y_pos * 32, map->x_pos * 32);
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
		printf("%d\n", ++map->move_player);
		if (map->map[map->y_pos - 1][map->x_pos] == 'C')
		{
			map->coins -= 1;
			map->map[map->y_pos - 1][map->x_pos] = '0';
		}
		replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 1);
		if (map->map[map->y_pos][map->x_pos] == 'E')
			replace_if_exit(map, map->y_pos * 32, map->x_pos * 32);
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
		printf("%d\n", ++map->move_player);
		if (map->map[map->y_pos + 1][map->x_pos] == 'C')
		{
			map->coins -= 1;
			map->map[map->y_pos + 1][map->x_pos] = '0';
		}
		replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 1);
		if (map->map[map->y_pos][map->x_pos] == 'E')
			replace_if_exit(map, map->y_pos * 32, map->x_pos * 32);
		map->y_pos += 1;
		replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 2);
		if (map->map[map->y_pos][map->x_pos] == 'E' && map->coins == 0)
			close_window(move, map);
	}
}
