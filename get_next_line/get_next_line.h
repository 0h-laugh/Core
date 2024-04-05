/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:43:38 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/05 15:56:59 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//main function
char	*get_next_line(int fd);

//main utils
void	ft_free(char **str, char **str2, char **str3);
char	*get_before_newline(const char *s);
char	*get_after_newline(const char *s);
void	ft_read(int fd, char **next, char **temp);

//utils
int	ft_check(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
