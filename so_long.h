/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:47:41 by proton            #+#    #+#             */
/*   Updated: 2024/03/22 15:23:58 by bproton          ###   ########.fr       */
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
# define BUFFER_SIZE 5000

# define TOP_BOT_WALL_ERROR write(1, "Error\nTop bot wall error\n", 25)
# define SIDE_WALL_ERROR write(1, "Error\nSide wall error\n", 22)
# define PLAYER_ERROR write (1, "Error\nPlayer error\n", 19)
# define COIN_ERROR write (1, "Error\nCoins error\n", 18)
# define EXIT_ERROR write (1, "Error\nExit error\n", 17)
# define SIZE_ERROR write (1, "Error\nMap size error\n", 21)
# define NOT_RECO_ERROR write (1, "Error\nWrong syntax error\n", 25)
# define MAP_ERROR write (1, "Error\nMap error\n", 16)


typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		x;
	int		y;
	int		endian;
}			t_data;

typedef struct s_map
{
	char		**map;
	int			x;
	int			y;
	int			player;
	int         coins;
	int         exit;
	int			x_pos;
	int			y_pos;
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
int 	close_win(int keycode, t_data *win);

#endif