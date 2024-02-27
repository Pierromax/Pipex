/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:20:03 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/11 05:38:56 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signe;
	int	resultat;

	resultat = 0;
	i = 0;
	signe = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signe = -signe;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		resultat = resultat * 10 + (nptr[i++] - 48);
	return (resultat * signe);
}
/* 
#include <stdio.h>
#include <stdlib.h>
int	main()
{
	const char s[]= " -2147483648";
	int	a;
	int	b;
	a = ft_atoi(s);
	b = atoi(s);
	printf("ft_atoi = %d\n",a);
	printf("   atoi = %d",b);
}
 */
