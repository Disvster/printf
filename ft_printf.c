/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:09:24 by manmaria          #+#    #+#             */
/*   Updated: 2025/04/21 18:30:32 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	varg;
	int		i;

	i = 0;
	va_start(varg, s);
	if (varg && *s)
	{
		while (s[i])
		{
			if (ft_strchr(s + i, '%') && ft_strchr(s + i + 1, 's'))
				ft_putstr_fd(va_arg(varg, char *), 1);
			ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	else if (*s)
		ft_putstr_fd((char *)s, 1);
	va_end(varg);
	return (0);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_printf("isto vai ter uma string %s <- aqui\n", "\"ola eu sou uma string!\"");
	return (0);
}
