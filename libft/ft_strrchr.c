/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:23:57 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/18 05:31:13 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	c %= 256;
	str = (char *)s;
	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == c)
			return (str + i);
		i--;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	char ptr[] = "okey les royepdkjfhjkldfh";
// 	int c = 't' + 256;
// 	char *str;
// 	str = ft_strrchr(ptr, c);
// 	printf("%s\n", str);
// }
