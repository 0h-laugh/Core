/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:50:48 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/07 15:28:37 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_isprint(31));
	printf("%d\n", isprint(31));
	printf("%d\n", ft_isprint(32));
	printf("%d\n", isprint(32));
	printf("%d\n", ft_isprint(69));
	printf("%d\n", isprint(69));
	printf("%d\n", ft_isprint(126));
	printf("%d\n", isprint(126));
	printf("%d\n", ft_isprint(127));
	printf("%d\n", isprint(127));
	printf("%d\n", ft_isprint(100000));
	printf("%d\n", isprint(100000));
	return (0);
}*/
