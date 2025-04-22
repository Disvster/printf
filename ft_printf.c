/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:09:24 by manmaria          #+#    #+#             */
/*   Updated: 2025/04/21 23:38:54 by manmaria         ###   ########.fr       */
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
	return (NULL);
}

void	ft_percent_scanner(const char *s, char *)
{
	
}
int	ft_printf(const char *s, ...)
{
	va_list	varg;
	int		i;

	va_start(varg, s);
	i = 0;
	while (s[i])
	{
		if (a1
	}
	va_end(varg);
	return (0);
}
/*
	if (*s)
	{
		while (s[i])
		{
			if (s[i] == '%' && s[i + 1] == 's')
			{
				ft_putstr_fd(va_arg(varg, char *), 1);
				i += 2;
			}
			ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	else if (*s)
		ft_putstr_fd((char *)s, 1);
	va_end(varg);
*/
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char *str = "\"ola eu sou uma string!\"";
	ft_printf("isto vai ter uma string -> %s <- aqui\n", str);
	return (0);
}
