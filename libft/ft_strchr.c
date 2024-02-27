/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:03:22 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/26 23:54:14 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if ((char)c == *str)
			return (str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	(void)ac;
	char	*s1;
	char	*s2;
	int c;

	c = atoi(av[2]);	
	s1 = strchr(av[1],c);
	s2 = ft_strchr(av[1],c);
	printf("strchr = %s\n", s1);
	printf("ft_strchr = %s", s2); 
}*/
