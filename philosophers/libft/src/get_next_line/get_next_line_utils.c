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

char    *ft_gstrjoin(char *line, char *buffer)
{
    size_t  line_len;
    size_t  buffer_len;
    char    *str;

    if (!line)
    {
        line = (char *)malloc(1);
        if (!line)
            return (NULL);
        line[0] = '\0';
    }
    line_len = ft_strlen(line);
    buffer_len = ft_strlen(buffer);
    str = malloc(line_len + buffer_len + 1);
    if (!str)
        return (NULL);
    ft_memcpy(str, line, line_len);
    ft_memcpy(str + line_len, buffer, buffer_len + 1);
    free(line);
    return (str);
}
