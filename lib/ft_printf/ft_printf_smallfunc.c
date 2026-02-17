/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_smallfunc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:54:51 by bproton           #+#    #+#             */
/*   Updated: 2023/12/04 14:50:59 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_n_reverse(unsigned long n, const char *str, char *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (n > 0)
	{
		dest[i] = str[n % 16];
		i++;
		n /= 16;
	}
	dest[i] = '\0';
	i--;
	while (i >= 0)
	{
		j += write(1, &dest[i], 1);
		i--;
	}
	free(dest);
	dest = NULL;
	return (j);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
