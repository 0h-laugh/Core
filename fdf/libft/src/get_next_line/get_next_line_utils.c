/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:45:01 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/26 14:07:01 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gstrjoin(char *line, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!line)
	{
		line = (char *)malloc(1 * sizeof(char));
		line[0] = '\0';
	}
	if (!line || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(line) + ft_strlen(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (line)
		while (line[++i] != '\0')
			str[i] = line[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(line) + ft_strlen(buffer)] = '\0';
	free(line);
	return (str);
}
