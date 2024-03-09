/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:06:48 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/07 15:48:59 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *) s;
	while (n > 0)
	{
		*(temp++) = (unsigned char) c;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int     main()
{
        char test[10] = "aaaaaaaaaa";
        ft_memset(test, 'z', 8);
        printf("ft_memset: %s\n", test);
        char test2[10] = "aaaaaaaaaa";
        memset(test2, 'z', 8);
        printf("memset: %s\n", test2);
        return (0);
}*/
