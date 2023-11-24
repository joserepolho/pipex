/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:26:22 by joaoribe          #+#    #+#             */
/*   Updated: 2023/11/23 23:19:23 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child(int *p_fd, char **av, char **ev, int i)
{
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	execute(av[i], ev);
}

void	parent(int *p_fd)
{
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	wait(0);
}

void	execute(char *cmd, char **ev)
{
	char	*path;
	char	**commands;

	commands = ft_split(cmd, 32);
	path = get_path(commands[0], ev);
	if (execve(path, commands, ev) == -1)
	{
		perror("Execution failure.");
		free(path);
		ft_free(commands);
		exit(EXIT_FAILURE);
	}
}
