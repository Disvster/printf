/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:58:24 by manmaria          #+#    #+#             */
/*   Updated: 2025/05/05 18:17:12 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substrmod(char **s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(*s))
		return (ft_strdup(""));
	if (len > ft_strlen(*s + start))
		len = ft_strlen(*s + start);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = (*s)[i + start];
		i++;
	}
	sub[i] = '\0';
	*s += ft_strlen(sub);
	return (sub);
}

int	ft_printf(const char *str, ...)
{
	va_list	var_args;
	int		count;
	int		i;
	char	*ret;

	va_start(var_args, str);
	i = 0;
	count = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
			i++;
		char *tmp = ft_substrmod((char **)&str, 0, i);
		count += ft_putstr(tmp);
		free(tmp);
		i = 0;
		if (str[i] == '%')
		{
			char spec = ft_strchr(str + ++i);
			ret = ft_see_format(&spec, var_args);
			int flag_skip = 0;
			ret = ft_flags(str + i, ret, &flag_skip, spec);
			i += flag_skip;
			count += ft_putstr(ret);
			str += i + 1;
			free(ret);
		}
	}
	va_end (var_args);
	return (count);
}
