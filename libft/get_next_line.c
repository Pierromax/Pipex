/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 04:50:02 by ple-guya          #+#    #+#             */
/*   Updated: 2024/02/06 18:57:47 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ('\n' == s[i])
			return (i + 1);
		i++;
	}
	return (0);
}

int	read_buffer(int fd, char *buffer)
{
	if (buffer[0] != '\0')
		return (1);
	if (read(fd, buffer, BUFFER_SIZE))
		return (1);
	return (0);
}

void	*get_next_buff(void *d, void *s, int nl)
{
	int		i;

	i = 0;
	if (!d && !s)
		return (NULL);
	while (BUFFER_SIZE > i)
	{
		if (nl && i < BUFFER_SIZE - nl)
			((char *)d)[i] = ((char *)s)[i];
		else
			((char *)d)[i] = '\0';
		i++;
	}
	return (d);
}

char	*get_next_line(int fd)
{
	static char		buffer[FD_MAX][BUFFER_SIZE];
	char			*line;
	int				nl;

	line = NULL;
	if (fd < 0 || read(fd, 0, BUFFER_SIZE * 0) || fd >= FD_MAX)
		return (NULL);
	while ((!is_newline(line)) && read_buffer(fd, (char *)buffer[fd]) > 0)
	{
		nl = is_newline(buffer[fd]);
		line = ft_strnjoin(line, buffer[fd], nl);
		if (!line)
			return (NULL);
		get_next_buff(buffer[fd], &buffer[fd][nl], nl);
	}
	return (line);
}
