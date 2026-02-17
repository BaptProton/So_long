/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:40:29 by bproton           #+#    #+#             */
/*   Updated: 2023/12/04 14:11:40 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	malloc_to_reverse(unsigned long n, char *str, char *str1, char c)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * 17);
	if (!temp)
		return (0);
	if (c == 'x')
		i += put_n_reverse(n, str, temp);
	else if (c == 'X')
		i += put_n_reverse(n, str1, temp);
	return (i);
}

static int	ft_countnumbers(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_strdup(const char *s)
{
	int				len;
	unsigned int	i;
	char			*ns;

	i = 0;
	len = ft_strlen((char *)s) + 1;
	ns = (char *)malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	if (ns == NULL)
		return (NULL);
	while (s[i])
	{
		ns[i] = s[i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*str;

	i = ft_countnumbers(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[i] = '\0';
	i--;
	while (n > 9)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	str[i] = n + '0';
	return (str);
}
