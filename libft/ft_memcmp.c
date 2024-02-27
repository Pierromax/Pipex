/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:05:01 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/26 22:11:50 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*st1;
	unsigned char		*st2;
	size_t				i;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (st1[i] == st2[i] && i < n - 1)
		i++;
	return (st1[i] - st2[i]);
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int	main()
{
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0}; 
	int	s1[] = {0, 42, 0 ,0};
	int 	s2[] = {0, 45, 0, 0};
	char s3[] = "lezgow";
	char s4[] = "lezgui";
	int	a = memcmp(s3, s3, 6);
	int	b = ft_memcmp(s3, s4 , 6);
	printf("memcmp = %d\n", a);
	printf("ft_memcmp = %d", b);

}*/