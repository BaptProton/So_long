/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:54:55 by bproton           #+#    #+#             */
/*   Updated: 2024/03/28 07:13:02 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_win(int keycode, t_map *win)
{
	
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(win->mlx, win->img);
		mlx_clear_window(win->mlx, win->win);
		mlx_destroy_window(win->mlx, win->win);
		exit (0);
	}
	return (0);
}

// int move_player(int keycode, t_map *map)
// {
// 	char **clone;

// 	clone = map->map;
// 	if (keycode == W_KEY)
// 	{
// 		map->map[map->y_pos][map->x_pos] == '0';
		
// 	}
// }

// void get_player_to_move(t_map *map)
// {
// 	mlx_hook(map->win, 2, 1L<<0, move_player, map);
	
// }
