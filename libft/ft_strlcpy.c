/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:14:21 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/26 23:53:16 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = (char)src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
/* #include <stdio.h>
int	main()
{
	char d[] = "AAAAAAAAAAA";
	char s[] = "coucou";
	size_t a;
	size_t b = 0;
	a = ft_strlcpy(d, s , b); 
	printf("destination = %s\nsource = %s\nde taille = %zu\n", d, s, a);
}*/