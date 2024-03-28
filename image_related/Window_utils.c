/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:54:55 by bproton           #+#    #+#             */
/*   Updated: 2024/03/28 15:44:17 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int move_player(int keycode, t_map *map)
{
	(void)map;
	if (keycode == ESC_KEY)
		exit (0);
	// if (keycode == W_KEY)
	return (1);
}

void get_player_to_move(t_map *map)
{
	mlx_hook(map->win, 2, 1L<<0, move_player, map);
}
