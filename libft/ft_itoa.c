/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:49:50 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/19 04:46:42 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	getsize(long int n)
{
	int	size;

	size = 0;
	if (n <= 0)
	{
		size++;
		n = -n;
	}
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			size;
	long int	nb;

	nb = n;
	size = getsize(n);
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[size] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		res[0] = '-';
	}
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[size - 1] = (nb % 10) + '0';
		nb /= 10;
		size--;
	}
	return (res);
}
/*
#include <stdio.h>
int	main()
{
	char *a;
	int i;

	i = 2;
	a = ft_itoa(i);
	printf("%s\n",a);
	
}*/
