/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:43:12 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/28 23:30:37 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		c;
	int			i;
	int			byte;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	i = 0;
	buffer[fd] = (char *)malloc(10000000);
	if (!buffer[fd])
		return (NULL);
	byte = read(fd, &c, 1);
	while (byte > 0)
	{
		buffer[fd][i] = c;
		i++;
		if (c == '\n' || c == EOF)
			break ;
		byte = read (fd, &c, 1);
	}
	if (i == 0 || byte < 0)
		return (free(buffer[fd]), NULL);
	buffer[fd][i] = '\0';
	return (buffer[fd]);
}
