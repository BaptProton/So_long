/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:52:13 by bproton           #+#    #+#             */
/*   Updated: 2023/12/04 16:30:24 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putstr(const char *s);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
char	*ft_strdup(const char *s);
int		malloc_to_reverse(unsigned long n, char *str, char *str1, char c);
int		put_n_reverse(unsigned long n, const char *str, char *dest);
size_t	ft_printadd(unsigned long ptr);
size_t	ft_address(int n);
size_t	ft_unsigned(unsigned int n);
int		ft_hexa(unsigned long n, char c);
size_t	ft_search(char c, va_list args);

#endif