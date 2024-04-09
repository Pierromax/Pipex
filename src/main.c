/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-guya <ple-guya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:34:55 by ple-guya          #+#    #+#             */
/*   Updated: 2024/04/08 16:06:56 by ple-guya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipe	p;

	if (ac != 5)
	{
		ft_putendl_fd("usage : File1 Cmd1 Cmd2 File2\n", 2);
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
