/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:34:55 by ple-guya          #+#    #+#             */
/*   Updated: 2024/04/08 16:58:51 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_file_permission(t_pipe *p)
{
	if (p->fdi == -1 && p->i == 0)
		close(p->pipefd[READ_END]);
	if (p->fdo == -1 && p->cmd[p->i + 1])
	{
		perror(p->outfile_name);
		exit(0);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipe	p;

	if (ac < 5)
	{
		ft_putendl_fd("usage : Infile Cmd1 ... Cmdn outfile\n", 2);
		return (0);
	}
	p.i = 0;
	get_file(&p, ac, av, env);
	while (p.cmd[p.i])
	{
		pipex(&p, env);
		p.i++;
	}
	clean_2dtab(p.dir);
	clean_2dtab(p.cmd);
	while (p.i--)
		wait(0);
	return (0);
}
