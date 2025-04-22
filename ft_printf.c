/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:09:24 by manmaria          #+#    #+#             */
/*   Updated: 2025/04/22 01:47:53 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"
#include <stdio.h>
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			break ;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return ((char *)s);
}

void	ft_percent_scanner(const char *s, va_list valet)
{
	int	i;
	
	i = 0;
	while (s[i]) 
	{
		if (s[i] == 'c')
			ft_putchar_fd(va_arg(valet, char), 1);
		else if (s[i] == 'i')
			ft_putnbr_fd(va_arg(valet, int), 1);
		i++

	}
}

int	ft_printf(const char *s, ...)
{
	va_list	valet;
	int		i;

	va_start(valet, s);
	i = 0;
	while (s[i])
	{
		 if (s[i] == '%')
			ft_percent_scanner(&s[i]);
	}
	va_end(valet);
	return (0);
}
/*
	if (*s)
	{
		while (s[i])
		{
			if (s[i] == '%' && s[i + 1] == 's')
			{
				ft_putstr_fd(va_arg(valet, char *), 1);
				i += 2;
			}
			ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	else if (*s)
		ft_putstr_fd((char *)s, 1);
	va_end(valet);
*/
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char *str = "\"ola eu sou uma string!\"";
	ft_printf("isto vai ter uma string -> %s <- aqui\n", str);
	return (0);
}
