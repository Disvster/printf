/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:54:09 by manmaria          #+#    #+#             */
/*   Updated: 2025/04/22 18:45:44 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_sep(char const c, char *sep)
{
	int	i;

	i = 0;
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

static size_t	count_words(char const *s, char *sep)
{
	size_t	cw;

	cw = 0;
	while (*s)
	{
		while (check_sep(*sep, sep) && *s)
			s++;
		if (*s)
			cw++;
		while (!check_sep(*s, sep) && *s)
			s++;
	}
	return (cw);
}

static size_t	count_letters(char const *s, char *sep, char **p_s)
{
	size_t	letters;

	letters = 0;
	while (!check_sep(*s, sep) && *s)
	{
		letters++;
		s++;
	}
	*p_s = (char *)s;
	return (letters);
}

static char	**free_split(char **save)
{
	char	**marcemon;

	marcemon = save;
	while (1)
	{
		if (!*save)
			break ;
		free(*save);
		save++;
	}
	free(marcemon);
	return (NULL);
}

char	**ft_nsplit(const char *s, char *sep)
{
	char	**save;
	char	**split;
	size_t	words;
	size_t	letters;

	words = count_words(s, sep);
	split = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!split)
		return (NULL);
	save = split;
	while (*s)
	{
		while (check_sep(*s, sep) && *s)
			s++;
		if (*s)
		{
			letters = count_letters(s, sep, (char **)&s);
			*split = ft_substr(s - letters, 0, letters);
			if (!*split)
				return (free_split(save));
			split++;
		}
	}
	return (save);
}
