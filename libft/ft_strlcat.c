/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:26:16 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/18 04:16:48 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	if ((!dst || !src) && !size)
		return (0);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	if (dlen > size - 1)
		return (size + slen);
	if (size == 0)
		return (slen);
	while (i < size - dlen - 1 && src[i])
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
/* 
#include <stdio.h>
int	main()
{
	char dst[100] = "B";
	char src[] = "AAAAAAAAA";
	size_t	i;

	i = ft_strlcat(dst, src, 6);
	printf("concatenation = %s\ntaille max = %zu\n",dst, i);
}*/
