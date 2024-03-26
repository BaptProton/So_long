/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:12:24 by proton            #+#    #+#             */
/*   Updated: 2024/03/26 10:34:25 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int select_image(t_data *win, int i)
{
    char *path;
    int img_w;
    int img_h;

    img_w = 32;
    img_h = 32;
    if (i = 1)
        path = "./image_related/walls.xpm";
    else
        path = "./image_related/floor.xpm";
    
    win.img = mlx_xpm_file_to_image(win.mlx, pf, &img_w, &img_h);

}

int map_generation(t_map *map, t_data *win)
{
    int x;
    int y;
    int i;

    i = 0;
    y = -1;
    while (++y < map->y)
    {
        x = -1;
        while (++x < map->x)
        {
            if (map->map[y][x] == '1')
            {
                i = 1;
                select_image(win, i);
            }
            else
            {
                i = 0;
                select_image(win, i);
            }
        }
    }
    return (1);
}

int image_initialization(t_map *map)
{
    t_data win;
    
    win.mlx = mlx_init();
    win.win = mlx_new_window(win.mlx, (map->x * 32), ((map->y + 1) * 32), "so_long");
    map_generation(map, &win);
    mlx_hook(win.win, 2, 1L<<0, close_win, &win);
    mlx_loop(win.mlx);
    return (0);
}