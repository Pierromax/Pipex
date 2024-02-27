/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:32:01 by ple-guya          #+#    #+#             */
/*   Updated: 2024/02/06 18:59:40 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *s)
{
	double	diz;
	double	dec;
	double	res;
	int		size;

	diz = (double)ft_atoi(s);
	while (*s && *s != '.')
		s++;
	if (*s == '.')
		s++;
	dec = (double)ft_atoi(s);
	size = ft_strlen(s);
	while (size != 0)
	{	
		dec /= 10;
		size--;
	}
	if (dec < 0)
		dec = 0;
	if (diz >= 0)
		res = diz + dec;
	if (diz < 0)
		res = diz - dec;
	return (res);
}

/* int main(int ac, char **av)
{
	(void)ac;
	printf("  atof = %f\n", atof(av[1]));
	printf("ft_atof = %f", ft_atof(av[1]));
} */