/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:22:12 by ple-guya          #+#    #+#             */
/*   Updated: 2023/11/18 05:34:18 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		new = malloc (sizeof(char));
		if (!new)
			return (NULL);
		*new = '\0';
		return (new);
	}
	if (start + len > slen)
		len = slen - start;
	new = malloc((len + 1));
	if (!new)
		return (NULL);
	ft_memcpy(new, s + start, len);
	new[len] = '\0';
	return (new);
}
/*#include  <stdio.h>
#include <string.h>
int	main()
{
	char	*str = "pierromax tjrs au max";
	char	*new;
	int	c;

	new = ft_substr(str, 100, 1);
	c = !strcmp(str, "");
	printf("%d \nancienne chaine = %s\n", c,str );
	printf("nouvelle chaine = %s\n",new );
	
}*/
