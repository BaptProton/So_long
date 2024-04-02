/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:35:26 by proton            #+#    #+#             */
/*   Updated: 2024/03/29 16:08:21 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_board(char **map, int fd)
{
	int	i;

	i = -1;
	while (map[++i] != NULL)
		free(map[i]);
	if (fd != 0)
		close(fd);
	return (1);
}

int	free_int_board(int **clone, t_map *map)
{
	int i;

	i = 1;
	(void)map;
	while (clone[++i])
		free(clone[i]);
	return (1);
}
