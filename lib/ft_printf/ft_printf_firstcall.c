/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_firstcall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:43:12 by bproton           #+#    #+#             */
/*   Updated: 2023/12/04 15:34:54 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printadd(unsigned long ptr)
{
	unsigned short	j;

	j = 0;
	j += ft_putstr("0x");
	j += ft_hexa(ptr, 'x');
	return (j);
}

int	ft_hexa(unsigned long n, char c)
{
	unsigned int	i;
	char			*str;
	char			*str1;

	str = "0123456789abcdef";
	str1 = "0123456789ABCDEF";
	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	i += malloc_to_reverse(n, str, str1, c);
	return (i);
}

size_t	ft_unsigned(unsigned int n)
{
	int		j;
	int		i;
	char	str[12];
	char	*template;

	j = 0;
	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	template = "0123456789";
	while (n > 0)
	{
		str[i] = template[n % 10];
		n /= 10;
		i++;
	}
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		j += write(1, &str[i], 1);
		i--;
	}
	return (j);
}

size_t	ft_address(int n)
{
	size_t	i;
	char	*add;

	i = 0;
	add = ft_itoa(n);
	while (add[i])
	{
		write(1, &add[i], 1);
		i++;
	}
	free (add);
	return (i);
}
