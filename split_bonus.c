/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:36:55 by joaoribe          #+#    #+#             */
/*   Updated: 2023/11/24 17:38:20 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_counts(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

void	*ft_words(char const *s, char c, char **bf)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			bf[i] = (char *)malloc(len + 1);
			if (!s || !bf[i])
				return (0);
			ft_strlcpy(bf[i], s, len + 1);
			i++;
			s += len;
		}
		else
			s++;
	}
	bf[i] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**bf;

	bf = (char **)malloc((ft_counts(s, c) + 1) * sizeof(char *));
	if (!s || !bf)
		return (0);
	ft_words(s, c, bf);
	return (bf);
}
