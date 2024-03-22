/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:21:11 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/07 16:20:34 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp_src;
	char	*temp_dest;
	size_t	c;

	c = 0;
	if (!dest && !src)
		return (NULL);
	temp_dest = (char *)dest;
	temp_src = (char *)src;
	if (temp_dest > temp_src)
		while (n-- > 0)
			temp_dest[n] = temp_src[n];
	else
	{
		while (c < n)
		{
			temp_dest[c] = temp_src[c];
			c++;
		}
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
	ft_memmove(dest, src, 2);
	printf("%s\n", dest);
	printf("%s\n",(const char *) src);
	return (0);
}*/
