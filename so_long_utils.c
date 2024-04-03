/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:35:26 by proton            #+#    #+#             */
/*   Updated: 2024/04/03 10:01:47 by proton           ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (((unsigned char)*s1 != '\0' || (unsigned char)*s2) && n > 0)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		n--;
		s1++;
		s2++;
	}
	return (1);
}

int	check_name(char *str)
{
	int		i;
	int		j;
	char	new[5];

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '.')
		{
			while (str[i] != '\0')
			{
				new[j] = str[i];
				j++;
				i++;
			}
			new[j] = '\0';
		}
	}
	if (!ft_strncmp(new, ".ber", j))
		return (0);
	return (1);
}