/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:09:37 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/18 04:43:19 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	memsize;

	memsize = nmemb * size;
	if (size && memsize / size != nmemb)
		return (NULL);
	str = malloc(memsize);
	if (!str)
		return (NULL);
	ft_bzero(str, memsize);
	return (str);
}
