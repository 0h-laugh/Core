/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:43:12 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/28 23:26:36 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	c;
	int		i;
	int		byte;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	i = 0;
	buffer = (char *)malloc(10000000);
	if (!buffer)
		return (NULL);
	byte = read(fd, &c, 1);
	while (byte > 0)
	{
		buffer[i] = c;
		i++;
		if (c == '\n' || c == EOF)
			break ;
		byte = read (fd, &c, 1);
	}
	if (i == 0 || byte < 0)
		return (free(buffer), NULL);
	buffer[i] = '\0';
	return (buffer);
}
