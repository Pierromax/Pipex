/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 04:57:07 by ple-guya          #+#    #+#             */
/*   Updated: 2024/04/03 19:17:43 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef FD_MAX
#  define FD_MAX 4000
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strlen_protect(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnjoin(char *s1, char *s2, int nl);
int		is_newline(char *s);
int		read_buffer(int fd, char	*buffer);

#endif