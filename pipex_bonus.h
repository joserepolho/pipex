/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:13:28 by joaoribe          #+#    #+#             */
/*   Updated: 2023/11/24 17:37:57 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	fork_and_pipe(char **av, int i, char **ev);
void	child(int *p_fd, char **av, char **ev, int i);
void	parent(int *p_fd);
void	execute(char *cmd, char **ev);
char	*get_path(char *cmd, char **ev);
char	*cmd_path(char **ev);
void	ft_free(char **s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
