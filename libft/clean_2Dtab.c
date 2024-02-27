/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_2Dtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:53:15 by ple-guya          #+#    #+#             */
/*   Updated: 2024/02/25 20:42:43 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	clean_2dtab(char **goodbye)
{
	unsigned int	i;

	i = 0;
	if (goodbye)
	{
		while (goodbye[i])
			free(goodbye[i++]);
		free(goodbye);
	}
}
