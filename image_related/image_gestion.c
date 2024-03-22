/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:12:24 by proton            #+#    #+#             */
/*   Updated: 2024/03/22 16:11:15 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int image_initialization(t_map *map)
{
    t_data win;
    char *path = "./image_related/walls_2.xpm";
    int img_width;
    int img_height;

    img_width = 600;
    img_height = 600;
    win.mlx = mlx_init();
    win.win = mlx_new_window(win.mlx, (map->x * 32), ((map->y + 1) * 32), "so_long");
    win.img = mlx_xpm_file_to_image(win.mlx, path, &img_width, &img_height);
    mlx_put_image_to_window(win.mlx, win.win, win.img, 1, 1);
    mlx_hook(win.win, 2, 1L<<0, close_win, &win);
    mlx_loop(win.mlx);
    return (0);
}