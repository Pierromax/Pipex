/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 04:47:05 by ple-guya          #+#    #+#             */
/*   Updated: 2024/01/26 16:02:36 by ple-guya         ###   ########.fr       */
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

char	*get_tab(long int nb, char *base, int size, char *res)
{	
	int			blen;

	blen = ft_strlen(base);
	if (nb < 0)
	{
		nb = -nb;
		res[0] = '-';
	}
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[size - 1] = base[nb % blen];
		nb /= blen;
		size--;
	}
	return (res);
}

int	ft_printoa_base(int n, char *base)
{
	char		*res;
	int			size;
	long int	nb;
	int			resize;

	nb = n;
	size = getsize(n, base);
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return (0);
	res[size] = '\0';
	res = get_tab(nb, base, size, res);
	resize = ft_strlen(res);
	write (1, res, resize);
	free(res);
	return (resize);
}

static size_t	ft_unitoa_addr(size_t n, char *base)
{
	char	*res;
	int		size;
	int		resize;
	int		blen;

	blen = ft_strlen(base);
	size = getsize(n, base);
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return (0);
	res[size] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[--size] = base[n % blen];
		n /= blen;
	}
	resize = ft_strlen(res);
	write (1, res, resize);
	free(res);
	return (resize);
}

int	putaddr(size_t ag, char *base)
{
	int	resize;

	resize = 0;
	if (ag)
	{
		write(1, "0x", 2);
		resize += 2;
	}
	else
		return (write(1, "(nil)", 5));
	resize += ft_unitoa_addr(ag, base);
	return (resize);
}
