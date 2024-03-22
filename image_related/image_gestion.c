/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:12:24 by proton            #+#    #+#             */
/*   Updated: 2024/03/22 10:27:00 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int image_initialization(t_map *map)
{
    t_data win;
    (void)map;
    char *path = "./image_related/walls.xpm";
    int img_width;
    int img_height;

    img_width = 32;
    img_height = 32;

    win.mlx = mlx_init();
    win.win = mlx_new_window(win.mlx, 1920, 1080, "so_long");
    win.img = mlx_xpm_file_to_image(win.mlx, path, &img_width, &img_height);
    if (win.img == NULL)
        printf("img is NULL\n");
    mlx_put_image_to_window(win.mlx, win.win, win.img, 300, 300);
    mlx_loop(win.mlx);
    return (0);
}