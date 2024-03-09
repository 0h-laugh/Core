/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:47:15 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/07 13:37:01 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*

#include <ctype.h>
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_isascii(-1));
	printf("%d\n", isascii(-1));
	printf("%d\n", ft_isascii(0));
	printf("%d\n", isascii(0));
	printf("%d\n", ft_isascii(128));
	printf("%d\n", isascii(128));
	printf("%d\n", ft_isascii(127));
	printf("%d\n", isascii(127));
	printf("%d\n", ft_isascii('a'));
	printf("%d\n", isascii('a'));
	printf("%d\n", ft_isascii(' '));
	printf("%d\n", isascii(' '));
	printf("%d\n", ft_isascii('.'));
	printf("%d\n", isascii('.'));
	printf("%d\n", ft_isascii(10000));
	printf("%d\n", isascii(10000));
	return (0);
}*/
