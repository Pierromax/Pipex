/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:32:58 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/18 04:39:44 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;

	if (!dest && !src)
		return (NULL);
	s = (char *)dest;
	while (n-- > 0)
		*s++ = *(char *)src++;
	return (dest);
}
