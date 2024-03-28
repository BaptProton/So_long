/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:12:24 by proton            #+#    #+#             */
/*   Updated: 2024/03/28 07:12:33 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	special_images(t_map *map, int posx, int posy)
{
	char	*path;

	if	(map->map[map->y_new][map->x_new] == '0')
		return (0);
	else if (map->map[map->y_new][map->x_new] == '1')
		return (0);
	else if (map->map[map->y_new][map->x_new] == 'E')
		path = "./image_related/Extract.xpm";
	else if (map->map[map->y_new][map->x_new] == 'C')
		path = "./image_related/coins.xpm";
	else
		path = "./image_related/player.xpm";
	map->img = mlx_xpm_file_to_image(map->mlx, path, &map->img_w, &map->img_h);
	mlx_put_image_to_window(map->mlx, map->win, map->img, posx, posy);
	return (1);
}

int	select_image(t_map *map, int posx, int posy)
{
	char	*path;

	map->img_w = 32;
	map->img_h = 32;
	if (map->map[map->y_new][map->x_new] == '1')
		path = "./image_related/walls.xpm";
	else
		path = "./image_related/floor.xpm";
	 map->img = mlx_xpm_file_to_image(map->mlx, path, &map->img_w, &map->img_h);
	mlx_put_image_to_window(map->mlx, map->win, map->img, posx, posy);
	return (1);
}

int	map_generation(t_map *map)
{
	int	posx;
	int	posy;

	posy = 0;
	while (++map->y_new < map->y + 1)
	{
		posx = 0;
		map->x_new = -1;
		while (++map->x_new < map->x)
		{
			select_image(map, posx, posy);
			special_images(map, posx, posy);
			posx += 32;
		}
		posy += 32;
	}
	return (1);
}

int	image_initialization(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, (map->x * 32), ((map->y + 1) * 32), "so_long");
	map_generation(map);
	// get_player_to_move(map);
	mlx_hook(map->win, 2, 1L<<0, close_win, map);
	mlx_loop(map->mlx);
	return (0);
}
