/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:59:21 by ple-guya          #+#    #+#             */
/*   Updated: 2024/03/22 16:02:57 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atol(const char *nptr)
{
	long int	i;
	int			signe;
	int			resultat;

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
