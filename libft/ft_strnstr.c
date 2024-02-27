/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:06:56 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/19 08:04:31 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (len == 0 && !big)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && len > i)
	{
		j = 0;
		while (big[i + j] == little[j] && len > i + j)
		{
			j++;
			if (little[j] == '\0')
			{
				return ((char *)big + i);
			}
		}
		i++;
	}
	return (NULL);
}
/*
#include <bsd/string.h>
#include <stdio.h>
int	main()
{
	char	*str;
	char	*st;
	//char * empty = (char*)"";
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	st = strnstr(haystack, needle, 0);
	str = ft_strnstr(haystack, needle, 0);
	
	printf("strnstr = %s\n", st);
	printf("ft_strnstr = %s\n",str );
}*/
