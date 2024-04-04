/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:47:41 by proton            #+#    #+#             */
/*   Updated: 2024/04/04 16:22:27 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "ft_printf/ft_printf.h"

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define BUFFER_SIZE 5000

# define TOP_BOT_WALL_ERROR "Error\nTop bot wall error\n"
# define SIDE_WALL_ERROR "Error\nSide wall error\n"
# define PLAYER_ERROR "Error\nPlayer error\n"
# define COIN_ERROR  "Error\nCoins error\n"
# define EXIT_ERROR  "Error\nExit error\n"
# define SIZE_ERROR  "Error\nMap size error\n"
# define NOT_RECO_ERROR  "Error\nWrong syntax error\n"
# define MAP_ERROR  "Error\nMap error\n"
# define NAME_FILE  "Error\nWrong name\n"
# define OPEN_FAULT  "Error\nOpen error\n"

typedef struct s_map
{
	void		*mlx;
	void		*win;
	void		*img;
	int			img_h;
	int			img_w;
	char		**map;
	int			x;
	int			y;
	int			player;
	int			coins;
	int			exit;
	int			x_pos;
	int			y_pos;
	int			x_new;
	int			y_new;
	int			move_player;
}				t_map;

char	**ft_split(char const *s, char c);
int		check_name(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		free_board(char **map);
int		check_map_basics(t_map *map);
int		check_first_last_row(int y, t_map *map);
int		check_middle_map_walls(t_map *map);
int		check_other_char(t_map *map);
int		first_sort(t_map *map);
int		is_safe(t_map *map, int x, int y);
int		image_initialization(t_map *map);
int		map_generation(t_map *map);
int		select_image(t_map *map, int posx, int posy);
int		special_images(t_map *map, int posx, int posy);
int		key_pressed(int keycode, t_map *map);
void	move_player_negativ_x(t_map *map, int move);
void	move_player_positiv_x(t_map *map, int move);
void	move_player_negativ_y(t_map *map, int move);
void	move_player_positiv_y(t_map *map, int move);
void	replace_player_image(t_map *map, int posy, int posx, int move);
void	replace_if_exit(t_map *map, int posy, int posx);
int		close_window(t_map *map);
int		search_recursive(t_map *map, char **clone, int x, int y);
void	replace_if_exit(t_map *map, int posy, int posx);

#endif