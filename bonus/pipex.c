/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:34:04 by ple-guya          #+#    #+#             */
/*   Updated: 2024/04/08 17:01:57 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	maman(t_pipe *p)
{
	if (p->i == 0)
	{
		if (pipe(p->pipefd) < 0)
		{
			perror("pipe");
			exit(1);
		}
		if (p->is_heredocs == 1)
		{
			if (pipe(p->pipedocs) < 0)
			{
				perror("pipe here_doc");
				exit(1);
			}
		}
	}
	else if (p->cmd[p->i + 1])
	{
		p->prev = p->pipefd[READ_END];
		if (pipe(p->pipefd) < 0)
		{
			perror("pipe");
			exit(1);
		}
	}
}

static void	papa(t_pipe *p)
{
	if (p->i == 0 && p->is_heredocs == 0)
	{
		close(p->fdi);
		close(p->pipefd[WRITE_END]);
	}
	if (p->i == 0 && p->is_heredocs == 1)
	{
		close(p->pipedocs[READ_END]);
		close(p->pipedocs[WRITE_END]);
		close(p->pipefd[WRITE_END]);
	}
	else if (!p->cmd[p->i + 1])
	{
		close(p->fdo);
		close(p->pipefd[READ_END]);
	}
	else
	{
		close(p->prev);
		close(p->pipefd[WRITE_END]);
	}
}

static void	other_child(t_pipe *p)
{
	if (!p->cmd[p->i + 1])
	{
		dup2(p->pipefd[READ_END], STDIN_FILENO);
		close(p->pipefd[READ_END]);
		dup2(p->fdo, STDOUT_FILENO);
		close(p->fdo);
	}
	else if (p->i > 0)
	{
		dup2(p->prev, STDIN_FILENO);
		close(p->prev);
		dup2(p->pipefd[WRITE_END], STDOUT_FILENO);
		close(p->pipefd[WRITE_END]);
	}
	else if (p->i == 0 && p->is_heredocs == 1)
	{
		ft_heredocs(p);
		dup2(p->pipedocs[READ_END], STDIN_FILENO);
		close(p->pipedocs[READ_END]);
		dup2(p->pipefd[WRITE_END], STDOUT_FILENO);
		close(p->pipefd[WRITE_END]);
		close(p->pipefd[READ_END]);
		close(p->fdo);
	}
}

static void	child(t_pipe *p, char **cmd, char **env)
{
	if (p->i == 0 && p->is_heredocs == 0)
	{
		close(p->pipefd[READ_END]);
		dup2(p->fdi, STDIN_FILENO);
		close(p->fdi);
		close(p->fdo);
		dup2(p->pipefd[WRITE_END], STDOUT_FILENO);
		close(p->pipefd[WRITE_END]);
	}
	else
		other_child(p);
	get_valid_path(p);
	check_file_permission(p);
	execve(p->path, cmd, env);
	perror(cmd[0]);
	close(p->pipefd[WRITE_END]);
	clean_2dtab(cmd);
	free(p->path);
	clean_2dtab(p->cmd);
	clean_2dtab(p->dir);
	close(p->fdo);
	close(p->fdi);
	exit(EXIT_FAILURE);
}

void	pipex(t_pipe *p, char **env)
{
	int		pid;
	char	**cmd;

	cmd = ft_split(p->cmd[p->i], ' ');
	if (!cmd)
		return ;
	maman(p);
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(1);
	}
	if (!pid)
		child(p, cmd, env);
	else
		papa(p);
	clean_2dtab(cmd);
}
