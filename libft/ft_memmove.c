/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:27:19 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/18 04:54:56 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (d < s)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	if (d > s)
	{
		d += n;
		s += n;
		while (n-- > 0)
			*(--d) = *(--s);
	}
	return (dest);
}
/*
 #include <stdio.h>
#include <string.h>
int	main()
{
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {'1', '2', '3', '4', '5', '\0', '-'};
	char sResult2[] = {'C', 67, 68, 68, 69, 0, 45};
	char sResultbis[] = {'1', '2', '3', '4', '5', '\0', '-'};
	
	printf("%p\n",ft_memmove(s0, s, 7));
	printf("%p\n",ft_memmove(s, s + 2, 0));
	printf("%p\n",ft_memmove(s + 2, s, 2));
	char *res;
	res = ft_memmove(sResult + 1, sResult, 2);
	char *res2;
	res2 = memmove(sResultbis + 1, sResultbis, 2);
	printf("%s\n",res);
	printf("%s\n",res2);

}*/
