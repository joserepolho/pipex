/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:16:30 by joaoribe          #+#    #+#             */
/*   Updated: 2023/11/24 17:34:33 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fork_and_pipe(char **av, int i, char **ev)
{
	int		ppz;
	int		p_fd[2];
	pid_t	pid;

	ppz = pipe(p_fd);
	pid = fork();
	if (ppz == -1 || pid == -1)
	{
		perror("Mission failed. You'll get them next time.");
		exit(EXIT_FAILURE);
	}
	if (!pid)
		child(p_fd, av, ev, i);
	else
		parent(p_fd);
}

int	main(int ac, char **av, char **ev)
{
	int	i;
	int	fdi;
	int	fdo;

	i = 2;
	if (ac < 5)
	{
		perror("Mission failed. You'll get them next time.");
		exit(EXIT_FAILURE);
	}
	else
	{
		fdi = open(av[1], O_RDONLY);
		fdo = open(av[ac - 1], O_TRUNC | O_CREAT | O_WRONLY);
		dup2(fdi, 0);
		dup2(fdo, 1);
		while (i < (ac - 2))
			fork_and_pipe(av, i++, ev);
		execute(av[i], ev);
	}
	return (0);
}
