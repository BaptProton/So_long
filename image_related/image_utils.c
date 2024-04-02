/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:54:55 by bproton           #+#    #+#             */
/*   Updated: 2024/04/02 16:07:21 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	replace_player_image(t_map *map, int posy, int posx, int move)
{
	char	*path_floor;
	char	*path_player;
	char	*path_exit;

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

void	replace_if_exit(t_map *map, int posy, int posx, int move)
{
	char	*path;

	path = "./image_related/Extract.xpm";
	if (move == 1)
	{
		
	}
}

int	key_pressed(int keycode, t_map *map)
{
	(void)map;
	if (keycode == ESC_KEY)
		close_window(keycode, map);
	if (keycode == W_KEY)
		move_player_negativ_y(map, keycode);
	else if (keycode == S_KEY)
		move_player_positiv_y(map, keycode);
	else if (keycode == A_KEY)
		move_player_negativ_x(map, keycode);
	else if (keycode == D_KEY)
		move_player_positiv_x(map, keycode);
	return (1);
}

int close_window(int keycode, t_map *map)
{
	(void)keycode;
	mlx_clear_window(map->mlx, map->win);
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_image(map->mlx, map->img);
	free_board(map->map, 0);
	exit(0);
}

// int finish_game(t_map *map)
// {
// 	if (map->map[map->y_pos][map->x_pos] == 'E' && map->coins == 0)
// 		exit(0);
// 	return (0);
// }
