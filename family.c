/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:00:30 by joaoribe          #+#    #+#             */
/*   Updated: 2023/11/24 18:38:02 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int *p_fd, char **av, char **ev)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	execute(av[2], ev);
}

void	parent(int *p_fd, char **av, char **ev)
{
	int	fd;

	fd = open(av[4], O_TRUNC | O_CREAT | O_WRONLY);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	execute(av[3], ev);
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
