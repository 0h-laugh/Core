/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:43:12 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/05 15:56:44 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **str, char **str2, char **str3)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (str3 && *str3)
	{
		free(*str3);
		*str3 = NULL;
	}
}

char	*get_before_newline(const char *s)
{
	char	*result;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	result = ft_calloc(i + 1, sizeof(result));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}

char	*get_after_newline(const char *s)
{
	char	*result;
	int		i;
	int 	j;

	j = 0;
	while (*s && s[j])
		j++;
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	result = ft_calloc((j - i) + 1, sizeof(result));
	if (!result)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		result[j] = s[i + j];
		j++;
	}
	return (result);
}

void	ft_read(int fd, char **next, char **temp)
{
	char	*buffer;
	size_t		c;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(buffer));
	if (!buffer)
		return ;
	c = 1;
	while (c > 0)
	{
		c = read(fd, buffer, BUFFER_SIZE);
		if (c == -1)
		{
			ft_free(&buffer, next, temp);
			return ;
		}
		buffer[c] = '\0';
		*temp = ft_strdup(*next);
		ft_free(&next, 0, 0);
		next = ft_strjoin(*temp, buffer);
		ft_free(&temp, 0, 0);
		if (ft_check(*next))
			break ;
	}
	ft_free(&buffer, 0, 0);
}

char	*get_next_line(int fd)
{
	static char *next = NULL;
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = NULL;
	line = NULL;
	ft_read(fd, &next, &temp);
	if (next != NULL && *next != '\0')
	{
		temp = ft_strdup(next);
		ft_free(&next, 0, 0);
		next = get_after_newline(temp);
		line = get_before_newline(temp);
		ft_free(&temp, 0, 0);
	}
	if (!line || *line == '\0')
		return (ft_free(&next, &line, &temp), NULL);
	return (line);
}