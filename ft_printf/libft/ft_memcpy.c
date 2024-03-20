/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:49:20 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/07 16:16:13 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (src == (void *)0 && dest == (void *)0)
		return (dest);
	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	while (n > 0)
	{
		*(temp_dest++) = *(temp_src++);
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char dest[10];
	const void *src = "aaaaa";
	memcpy(dest, src, 9);
	printf("%s\n", dest);
	return (0);
}*/
