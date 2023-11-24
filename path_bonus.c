/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:36:04 by joaoribe          #+#    #+#             */
/*   Updated: 2023/11/24 17:36:25 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	*cmd_path(char **ev)
{
	while (ft_strncmp("PATH", *ev, 4))
		ev++;
	return (*ev + 5);
}

char	*get_path(char *cmd, char **ev)
{
	int		i;
	char	**paths;
	char	*path;

	i = 0;
	paths = ft_split(cmd_path(ev), ':');
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, cmd);
		if (!access(path, F_OK | X_OK))
		{
			ft_free(paths);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free(paths);
	return (0);
}
