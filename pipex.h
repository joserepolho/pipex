/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:38:20 by dpaco             #+#    #+#             */
/*   Updated: 2023/11/24 17:58:17 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

void	error_check(int ac, int *p_fd, pid_t pid);
void	child(int *p_fd, char **av, char **ev);
void	parent(int *p_fd, char **av, char **ev);
void	execute(char *cmd, char **ev);
char	*get_path(char *cmd, char **ev);
char	*cmd_path(char **ev);
void	ft_free(char **s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
