/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:54:50 by joaoribe          #+#    #+#             */
/*   Updated: 2023/11/24 17:53:26 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **ev)
{
	int		p_fd[2];
	int		ppz;
	pid_t	pid;

	ppz = pipe(p_fd);
	pid = fork();
	if (ac != 5 || ppz == -1 || pid == -1)
	{
		perror("Mission failed. You'll get them next time.");
		exit(EXIT_FAILURE);
	}
	if (!pid)
		child(p_fd, av, ev);
	else
	{
		wait(0);
		parent(p_fd, av, ev);
	}
	return (0);
}
