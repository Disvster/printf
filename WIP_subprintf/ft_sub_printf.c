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

int	ft_putstr_spec(const char *s, char spec)
{
	int	i;

	i = 0;
	if (spec == 1)
	{
		if (s[0] == 0)
		{
			i += write(1, "", 1);
			i += write(1, &s[1], ft_strlen(&s[1]));
		}
		else
		{
			i += write(1, s, ft_strlen(s));
			i += write(1, "", 1);
		}
		return (i);
	}
	if (spec == 'c' && !*s)
		i += write(1, "", 1);
	else
		i += write(1, s, ft_strlen(s));
	return (i);
}

int	ft_setpercent(va_list var_args, const char *str, int *p, int count)
{
	char	*ret;
	char	spec;
	int		flag_skip;

	flag_skip = 0;
	ret = 0;
	spec = ft_strchr(str + ++(*p));
	ret = ft_see_format(&spec, var_args);
	ret = ft_flags(str + *p, ret, &flag_skip, &spec);
	*p += flag_skip + 1;
	count += ft_putstr_spec(ret, spec);
	free(ret);
	return (count);
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
			count = ft_setpercent(var_args, str, &i, count);
		// save substrmod in tmp, then save ret aka set percent's ret in another temp
		// strjoin the two of them into a new FINAL str
		// keep doing this until we have everything in a single string, then print it
		// in a single call to printf
		// strjoin would be like
		// while (s[i] && s[i] != '%')
		//		i++;
		// s1 = malloc(i + 1);
		// if (str[i] == '%')
		//		ret = ft_setpercent();
		// if (nulls werent a pain in the ass)
		//		sfinal = malloc (len(s1) + len(re) + 1);
		// free(s1);
		// s1 = sfinal;
		// when s1 == 0;
		// write(1, sfinal, len(final));
		// can't use strlen :D check ft_putstr_spec to see why :D
	}
	va_end (var_args);
	return (count);
}

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
	while (i < len && (*s)[i] != '%')
	{
		sub[i] = (*s)[i + start];
		i++;
	}
	sub[i] = '\0';
	*s += ft_strlen(sub);
	return (sub);
}
