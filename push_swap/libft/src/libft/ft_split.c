/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:19:35 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/26 15:50:02 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !count)
		{
			count = 1;
			i++;
		}
		else if (*s == c)
			count = 0;
		s++;
	}
	return (i);
}

static void	ft_free(char **s)
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

char	**ft_split(const char *s, char c)
{
	int		n;
	int		i;
	char	*start;
	char	**dest;

	i = 0;
	n = ft_wordcount(s, c);
	dest = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	while (i < n)
	{
		while (*s == c)
			s++;
		start = (char *)s;
		while (*s && *s != c)
			s++;
		dest[i] = ft_substr(start, 0, s - start);
		if (!dest[i])
			return (ft_free(dest), NULL);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
