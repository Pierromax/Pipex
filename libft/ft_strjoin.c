/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:13:30 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/18 05:26:14 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	size_t		i;
	size_t		slen;
	char		*join;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	slen = ft_strlen(s1);
	len = slen + ft_strlen(s2);
	join = malloc(len + 1);
	if (!join)
		return (NULL);
	ft_memcpy(join, s1, slen);
	while (s2[i])
		join[slen++] = (char)s2[i++];
	join[len] = '\0';
	return (join);
}
