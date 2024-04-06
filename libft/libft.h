/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:14:06 by ple-guya          #+#    #+#             */
/*   Updated: 2024/03/22 16:02:34 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 4000
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

// int and size_t value whith char
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isascii(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

//int value with string
int			ft_atoi(const char *nptr);
long int	ft_atol(const char *nptr);
double		ft_atof(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

//get_size functions
size_t		ft_strlen(const char *s);
int			ft_tablen(char **tab);

//void with string
void		*ft_memset(void *s, int c, size_t n);
void		*ft_bzero(void *s, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

//void with tab
void		clean_2dtab(char **goodbye);

//writng functions
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

// string manipulation
char		*ft_strchr(const char *s, int c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);

// liste chainee
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void*));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//printf
int			ft_putchar(char c);
int			ft_putestr(char *s);
int			ft_printoa_base(int n, char *base);
int			ft_printf(const char *s, ...);
int			ft_unitoa_base(unsigned int n, char *base);
int			putaddr(size_t ag, char *base);

//get_next_line
char		*get_next_line(int fd);
void		*get_next_buff(void *d, void *s, int nl);
char		*ft_strnjoin(char *s1, char *s2, int l);
int			is_newline(char *s);
int			read_buffer(int fd, char *buffer);
int			ft_strglen(char *s);

#endif
