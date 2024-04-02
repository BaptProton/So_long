/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:54:55 by bproton           #+#    #+#             */
/*   Updated: 2024/04/02 10:30:30 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void replace_player_image(t_map *map, int posy, int posx, int move)
{
	char	*path_floor;
	char	*path_player;

	path_floor = "./image_related/floor.xpm";
	path_player = "./image_related/player.xpm";
	if (move == 1)
	{
		map->img = mlx_xpm_file_to_image(map->mlx, path_floor, &map->img_w, &map->img_h);
		mlx_put_image_to_window(map->mlx, map->win, map->img, posx, posy);
	}
	else
	{
		map->img = mlx_xpm_file_to_image(map->mlx, path_floor, &map->img_w, &map->img_h);
		mlx_put_image_to_window(map->mlx, map->win, map->img, posx, posy);
		map->img = mlx_xpm_file_to_image(map->mlx, path_player, &map->img_w, &map->img_h);
		mlx_put_image_to_window(map->mlx, map->win, map->img, posx, posy);
	}
}

void move_player_x(t_map *map, int move)
{
	if (move == A_KEY && map->map[map->y_pos][map->x_pos - 1] != '1')
	{
			if (map->map[map->y_pos][map->x_pos - 1] == 'C')
				map->coins -= 1;
			replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 1);
			map->x_pos -= 1;
			replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 2);
	}
	else if (move == D_KEY && map->map[map->y_pos][map->x_pos + 1] != '1')
	{
			if (map->map[map->y_pos][map->x_pos + 1] == 'C')
				map->coins -= 1;
			replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 1);
			map->x_pos += 1;
			replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 2);
	}

}

void move_player_y(t_map *map, int move)
{
	if (move == W_KEY && map->map[map->y_pos - 1][map->x_pos] != '1')
	{
			if (map->map[map->y_pos - 1][map->x_pos] == 'C')
				map->coins -= 1;
			replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 1);
			map->y_pos -= 1;
			replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 2);
	}
	else if (move == S_KEY && map->map[map->y_pos + 1][map->x_pos] != '1')
	{
			if (map->map[map->y_pos + 1][map->x_pos] == 'C')
				map->coins -= 1;
			replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 1);
			map->y_pos += 1;
			replace_player_image(map, map->y_pos * 32, map->x_pos * 32, 2);
	}
}

int key_pressed(int keycode, t_map *map)
{
	(void)map;
	if (keycode == ESC_KEY)
		exit (0);
	if (keycode == W_KEY)
		move_player_y(map, keycode);
	else if (keycode == S_KEY)
		move_player_y(map, keycode);
	else if (keycode == A_KEY)
		move_player_x(map, keycode);
	else if (keycode == D_KEY)
		move_player_x(map, keycode);
	return (1);
}

int close_window(int keycode, t_map *map)
{
	(void)keycode;
	(void)map;
	// free_board(map->map, 0);
	exit(0);
}
