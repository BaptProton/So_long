/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:35:26 by proton            #+#    #+#             */
/*   Updated: 2024/04/03 16:41:20 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_board(char **map, int fd)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[++i])
		{
			free(map[i]);
		}
		free(map);
	}
	if (fd != 0)
		close(fd);
	return (1);
}

int	ft_strcmp( char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if ((char)s1[i] != (char)s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_name(char *str)
{
	int	j;

	j = 0;
	while (str[j])
		j++;
	if (j <= 4)
		return (0);
	if (!ft_strcmp(str + (j - 4), ".ber"))
		return (0);
	return (1);
}