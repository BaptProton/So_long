/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:12:24 by proton            #+#    #+#             */
/*   Updated: 2024/03/27 14:58:17 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	special_images(t_data *win, t_map *map, int posx, int posy)
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
	win->img = mlx_xpm_file_to_image(win->mlx, path, &win->img_w, &win->img_h);
	mlx_put_image_to_window(win->mlx, win->win, win->img, posx, posy);
	return (1);
}

int	select_image(t_data *win, t_map *map, int posx, int posy)
{
	char	*path;

	win->img_w = 32;
	win->img_h = 32;
	if (map->map[map->y_new][map->x_new] == '1')
		path = "./image_related/walls.xpm";
	else
		path = "./image_related/floor.xpm";
	win->img = mlx_xpm_file_to_image(win->mlx, path, &win->img_w, &win->img_h);
	mlx_put_image_to_window(win->mlx, win->win, win->img, posx, posy);
	return (1);
}

int	map_generation(t_map *map, t_data *win)
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
			select_image(win, map, posx, posy);
			special_images(win, map, posx, posy);
			posx += 32;
		}
		posy += 32;
	}
	return (1);
}

int	image_initialization(t_map *map)
{
	t_data	win;
	
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, (map->x * 32), ((map->y + 1) * 32), "so_long");
	map_generation(map, &win);
	mlx_hook(win.win, 2, 1L<<0, close_win, &win);
	mlx_loop(win.mlx);
	return (0);
}
