/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:51:17 by ple-guya          #+#    #+#             */
/*   Updated: 2024/02/06 19:00:58 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsize(long int n, char *base)
{
	int	size;
	int	blen;

	blen = ft_strlen(base);
	size = 0;
	if (n <= 0)
	{
		size++;
		n = -n;
	}
	while (n > 0)
	{
		size++;
		n /= blen;
	}
	return (size);
}

int	ft_unitoa_base(unsigned int n, char *base)
{
	char			*res;
	int				size;
	unsigned int	nb;
	int				resize;
	int				blen;

	blen = ft_strlen(base);
	nb = n;
	size = getsize(n, base);
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return (0);
	res[size] = '\0';
	if (nb == 0)
		res[0] = '0';
	while (nb != 0)
	{
		res[size - 1] = base[nb % blen];
		nb /= blen;
		size--;
	}
	resize = ft_strlen(res);
	write (1, res, resize);
	free(res);
	return (resize);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putestr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
