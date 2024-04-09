/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:34:47 by ple-guya          #+#    #+#             */
/*   Updated: 2024/04/08 16:11:07 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

# define READ_END 0
# define WRITE_END 1

typedef struct s_pipe
{
	int		pipefd[2];
	char	**dir;
	char	**cmd;
	char	*path;
	int		fdi;
	int		fdo;
	int		i;
	int		prev;
	int		is_heredocs;
	int		pipedocs[2];
	char	*limiter;
	char	*outfile_name;
}	t_pipe;

void	init_env(char **env, t_pipe *p);
void	init_cmd(int ac, char	**av, t_pipe *p);
void	get_valid_path(t_pipe *p);
void	clean_2dtab(char **goodbye);
void	pipex(t_pipe *p, char **env);
void	get_file(t_pipe *p, int ac, char **av, char **env);
void	ft_heredocs(t_pipe *p);
void	check_file_permission(t_pipe *p);

#endif