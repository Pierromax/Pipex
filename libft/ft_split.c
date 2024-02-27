/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:32:25 by ple-guya          #+#    #+#             */
/*   Updated: 2024/01/11 04:25:57 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	i;
	int		new_word;

	i = 0;
	new_word = 1;
	while (*s)
	{
		if (*s != c && new_word == 1)
		{
			new_word = 0;
			i++;
		}
		if (*s == c)
			new_word = 1;
		s++;
	}
	return (i);
}

static char	**free_split(char **split)
{
	unsigned int	i;

	i = 0;
	if (split)
	{
		while (split[i])
			free(split[i++]);
		free(split);
	}
	return (split);
}

static	int	size_word(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**splited(char **split, char *st, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*st)
	{
		if (*st != c)
		{
			split[i] = (char *)malloc(size_word(st, c) + 1);
			if (!split[i])
				return (free_split(split));
			j = 0;
			while (*st && *st != c)
				split[i][j++] = *st++;
			split[i][j] = '\0';
			i++;
		}
		else
			st++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*st;

	if (!s)
		return (NULL);
	st = (char *)s;
	split = malloc((count_words(st, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = splited (split, st, c);
	return (split);
}
/*
#include <stdio.h>
int	main()
{
	int	i = 0;
	char *s = "  tripouille  42  ";
	char **split = ft_split(s,' ');
	while (split[i])
		printf("%s",split[i++]);
}*/
