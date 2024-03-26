/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:54:55 by bproton           #+#    #+#             */
/*   Updated: 2024/03/22 17:12:10 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int close_win(int keycode, t_data *win)
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

int print_move(int keycode, t_data *win)
{
    (void)win;
    
    if (keycode != 0)
        printf("move %d\n", keycode);
    return (0);
}