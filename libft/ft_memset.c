/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:11:21 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/19 06:25:24 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n-- > 0)
		*str++ = (unsigned char)c;
	return (s);
}

/* #include <stdio.h>

int	main(void)
{
	char	str[] = "Hello, World !";

	printf("before memset : %s\n", str);
	ft_memset(str, 84, 5);
	printf("After memset : %s\n", str);
	return (0);
} */
