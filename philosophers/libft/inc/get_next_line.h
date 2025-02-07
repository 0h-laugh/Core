/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:43:38 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/26 14:08:42 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8192
# endif

//main function
char	*get_next_line(int fd);

//main utils
char	*ft_read(int fd, char *line);
char	*ft_get_line(char *line);
char	*ft_new_line(char *line);

//utils
char	*ft_gstrjoin(char *line, char *buffer);

#endif
