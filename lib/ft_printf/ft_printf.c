/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:41:49 by bproton           #+#    #+#             */
/*   Updated: 2023/12/04 16:45:30 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_search(char c, va_list args)
{
	size_t	i;

	i = 0;
	if (c == '%')
		i += ft_putchar(c);
	else if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (c == 's')
		i += ft_putstr(va_arg(args, const char *));
	else if (c == 'p')
		i += ft_printadd(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		i += ft_address(va_arg(args, int));
	else if (c == 'u')
		i += ft_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		i += ft_hexa(va_arg(args, unsigned int), c);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	j;

	va_start(args, str);
	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			j += ft_search(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			j++;
		}
		i++;
	}
	va_end(args);
	return (j);
}

#ifdef FT_PRINTF_DEMO
int	main(void)
{
	char	*test;

	test = "husregrhuaefhaghawehiopghopiagphiogeaohipgrarhopaghopigaehiopgaohpgraiohghopihopewhopgewhopghgwhiopgehiop";
	ft_printf("%s", test);
}
#endif