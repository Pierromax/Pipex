/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:03:39 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/02 22:13:49 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main()
{
	int	a;
	int	b;
	int	c;

	a = 67;
	b = ft_tolower(a);
	c = tolower(a);
	printf("ft_tolower = %c\n",b );
	printf("   tolower = %c\n",c );
}*/
