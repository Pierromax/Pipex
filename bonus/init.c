/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 03:08:38 by ple-guya          #+#    #+#             */
/*   Updated: 2024/02/28 22:09:56 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_file(t_pipe *p, int ac, char **av, char **env)
{
	p->fdi = open(av[1], O_RDWR);
	if (p->fdi == -1)
		perror(av[1]);
	p->fdo = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	init_env(env, p);
	init_cmd(ac, av, p);
}

void	init_cmd(int ac, char **av, t_pipe *p)
{
	int	i;

	i = 0;
	p->cmd = malloc(sizeof(char *) * (ac - 2));
	if (!p->cmd)
		return (clean_2dtab(p->cmd));
	av += 2;
	while (i < ac - 3)
	{
		p->cmd[i] = ft_strdup(*av);
		if (!p->cmd[i])
			return (clean_2dtab(p->cmd));
		av++;
		i++;
	}
	p->cmd[i] = NULL;
}

void	init_env(char **env, t_pipe *p)
{
	int		i;
	char	*tmp;
	char	**dir_tmp;

	i = 0;
	while (ft_strncmp(*env, "PATH=", 5) != 0)
		env++;
	dir_tmp = ft_split(*env + 5, ':');
	if (!dir_tmp)
		return (clean_2dtab(dir_tmp));
	p->dir = malloc(sizeof(char *) * (ft_tablen(dir_tmp) + 1));
	while (dir_tmp[i])
	{
		tmp = ft_strjoin(dir_tmp[i], "/");
		if (!tmp)
			break ;
		p->dir[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	p->dir[i] = NULL;
	clean_2dtab(dir_tmp);
}

void	get_valid_path(t_pipe *p)
{
	char	**cmd_tmp;
	int		i;

	i = 0;
	if (ft_strchr(p->cmd[p->i], '/'))
	{
		p->path = p->cmd[p->i];
		return ;
	}
	cmd_tmp = ft_split(p->cmd[p->i], ' ');
	if (!cmd_tmp)
		return (clean_2dtab(cmd_tmp));
	while (p->dir[i])
	{
		p->path = ft_strjoin(p->dir[i], cmd_tmp[0]);
		if (!p->path)
			break ;
		if (access(p->path, F_OK | X_OK) == 0)
			return (clean_2dtab(cmd_tmp));
		else
			free(p->path);
		i++;
	}
	p->path = ft_strdup("");
	clean_2dtab(cmd_tmp);
}
