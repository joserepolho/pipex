/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:32:26 by joaoribe          #+#    #+#             */
/*   Updated: 2023/11/24 17:38:33 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i])
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*bf;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	bf = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!bf || !s1 || !s2)
		return (0);
	while (s1[i])
	{
		bf[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		bf[i + j] = s2[j];
		j++;
	}
	bf[i + j] = '\0';
	return (bf);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
	{
		*dst = *src;
		return (0);
	}
	i = 0;
	if (size)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
