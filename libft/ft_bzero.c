/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:25:56 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/07 16:11:58 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *) s;
	while (n > 0)
	{
		*(temp++) = 0;
		n--;
	}
}
/*
#include <stdio.h>
#include <strings.h>

int	main()
{
	char test[11] = "aaaaaaaaaa";
	ft_bzero(test, 1);
	printf("%s\n", test);
	char test2[11] = "aaaaaaaaaa";
	bzero(test2, 1);
	printf("%s\n", test2);
	return (0);
}*/
