/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:32:52 by ple-guya          #+#    #+#             */
/*   Updated: 2024/04/03 19:15:16 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char		buffer[BUFFER_SIZE];
	char			*line;
	int				nl;

	line = NULL;
	if (fd < 0 || read(fd, 0, BUFFER_SIZE * 0))
		return (NULL);
	while ((!is_newline(line)) && read_buffer(fd, (char *)buffer) > 0)
	{
		nl = is_newline(buffer);
		line = ft_strnjoin(line, buffer, nl);
		if (!line)
			return (NULL);
		get_next_buff(buffer, &buffer[nl], nl);
	}
	return (line);
}

//  int main ()
// {
// 	int fd;
// 	char *str;
// 	// int i = 0;

// 	fd = open("test.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd);
//  	} 
// /*  	while (i  < 4)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		i++;
// 	}  */
// 	close (fd);
// 	return 0;
// }