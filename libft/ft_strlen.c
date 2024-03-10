/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:58:36 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/07 15:50:05 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	printf("%ld\n", ft_strlen("aaaaaaaaaa"));
	printf("%ld\n", strlen("aaaaaaaaaa"));
	printf("%ld\n", ft_strlen(""));
	printf("%ld\n", strlen(""));
	printf("%ld\n", ft_strlen("a"));
	printf("%ld\n", strlen("a"));
	printf("%ld\n", ft_strlen("12345"));
	printf("%ld\n", strlen("12345"));
	printf("%ld\n", ft_strlen("ssssssssssssssssssssssssssssssssssssssssss"));
	printf("%ld\n", strlen("ssssssssssssssssssssssssssssssssssssssssss"));
	printf("%ld\n", ft_strlen(" 1 "));
	printf("%ld\n", strlen(" 1 "));
	return (0);
}*/
