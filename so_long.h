/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:47:41 by proton            #+#    #+#             */
/*   Updated: 2024/03/27 18:04:28 by proton           ###   ########.fr       */
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

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define BUFFER_SIZE 5000

# define TOP_BOT_WALL_ERROR write(1, "Error\nTop bot wall error\n", 25)
# define SIDE_WALL_ERROR write(1, "Error\nSide wall error\n", 22)
# define PLAYER_ERROR write (1, "Error\nPlayer error\n", 19)
# define COIN_ERROR write (1, "Error\nCoins error\n", 18)
# define EXIT_ERROR write (1, "Error\nExit error\n", 17)
# define SIZE_ERROR write (1, "Error\nMap size error\n", 21)
# define NOT_RECO_ERROR write (1, "Error\nWrong syntax error\n", 25)
# define MAP_ERROR write (1, "Error\nMap error\n", 16)


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
	int         coins;
	int         exit;
	int			x_pos;
	int			y_pos;
	int			x_new;
	int			y_new;
}				t_map;

char	**ft_split(char const *s, char c);
int		free_board(char **map, int fd);
int		check_map_basics(t_map *map);
int		check_first_last_row(int y, t_map *map);
int 	check_middle_map_walls(t_map *map);
int 	check_other_char(t_map *map);
int		first_sort(t_map *map);
int		is_safe(t_map *map, int x, int y);
int		recursive_search(t_map *map, int **clone, int x, int y);
int		**clone_arrays(t_map *map);
int		image_initialization(t_map *map);
int 	close_win(int keycode, t_map *win);
int		map_generation(t_map *map);
int 	select_image(t_map *map, int posx, int posy);
int		special_images(t_map *map, int posx, int posy);
void	get_player_to_move(t_map *map);

#endif