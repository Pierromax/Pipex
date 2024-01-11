/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:09:39 by ple-guya          #+#    #+#             */
/*   Updated: 2024/01/11 14:25:34 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnjoin(char *s1, char *s2, int nl)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen(s1);
	if (nl)
		len2 = nl;
	else
		len2 = ft_strlen(s2);
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	str[len2 + len1] = '\0';
	while (len2--)
		str[len1 + len2] = s2[len2];
	while (len1--)
		str[len1] = s1[len1];
	free(s1);
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	memsize;

	memsize = nmemb * size;
	if (size && memsize / size != nmemb)
		return (NULL);
	str = malloc(memsize);
	if (!str)
		return (NULL);
	ft_bzero(str, memsize);
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n-- > 0)
		*str++ = '\0';
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;

	if (!dest && !src)
		return (NULL);
	s = (char *)dest;
	while (n-- > 0)
		*s++ = *(char *)src++;
	return (dest);
}
