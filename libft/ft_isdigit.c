/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:31:34 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/07 13:37:39 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}
/*

#include <ctype.h>
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_isdigit('0'));
	printf("%d\n", isdigit('0'));
	printf("%d\n", ft_isdigit('4'));
	printf("%d\n", isdigit('4'));
	printf("%d\n", ft_isdigit('9'));
	printf("%d\n", isdigit('9'));
	printf("%d\n", ft_isdigit(0));
	printf("%d\n", isdigit(0));
	printf("%d\n", ft_isdigit('a'));
	printf("%d\n", isdigit('a'));
	printf("%d\n", ft_isdigit(' '));
	printf("%d\n", isdigit(' '));
	printf("%d\n", ft_isdigit('z'));
	printf("%d\n", isdigit('z'));
	printf("%d\n", ft_isdigit('Z'));
	printf("%d\n", isdigit('Z'));
	printf("%d\n", ft_isdigit('.'));
	printf("%d\n", isdigit('.'));
	printf("%d\n", ft_isdigit('1'));
	printf("%d\n", isdigit('1'));
	printf("%d\n", ft_isdigit(49));
	printf("%d\n", isdigit(49));
	printf("%d\n", ft_isdigit(56));
	printf("%d\n", isdigit(56));
	printf("%d\n", ft_isdigit(1000));
	printf("%d\n", isdigit(1000));
	printf("%d\n", ft_isdigit(-1));
	printf("%d\n", isdigit(-1));
	return (0);
}*/
