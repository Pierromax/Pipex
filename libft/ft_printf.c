/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:40:40 by ple-guya          #+#    #+#             */
/*   Updated: 2024/01/26 18:28:57 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isformat(char c)
{
	return ((c == 'p' || c == 's' || c == 'd'
			|| c == 'i' || c == 'u' || c == 'x'
			|| c == 'X' || c == '%'));
}

static int	ft_formats(va_list ag, char format)
{
	if (format == '%')
		return (ft_putchar('%'));
	if (format == 'c')
		return (ft_putchar(va_arg(ag, int)));
	if (format == 's')
		return ((ft_putestr(va_arg(ag, char *))));
	if (format == 'p')
		return ((putaddr(va_arg(ag, size_t), "0123456789abcdef")));
	if (format == 'd')
		return ((ft_printoa_base(va_arg(ag, int), "0123456789")));
	if (format == 'i')
		return ((ft_printoa_base(va_arg(ag, int), "0123456789")));
	if (format == 'u')
		return ((ft_unitoa_base(va_arg(ag, unsigned int), "0123456789")));
	if (format == 'x')
		return ((ft_unitoa_base(va_arg(ag, int), "0123456789abcdef")));
	if (format == 'X')
		return ((ft_unitoa_base(va_arg(ag, int), "0123456789ABCDEF")));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		plen;
	va_list	ag;

	plen = 0;
	if (s == 0)
		return (-1);
	va_start(ag, s);
	while (*s)
	{
		if (*s == '%' && isformat(*s++))
			plen += ft_formats(ag, *s);
		else
			plen += ft_putchar(*s);
		s++;
	}
	va_end(ag);
	return (plen);
}
