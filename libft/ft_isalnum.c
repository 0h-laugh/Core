/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:34:45 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/07 13:37:26 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (8);
	return (0);
}
/*

#include <ctype.h>
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_isalnum(47));
	printf("%d\n", isalnum(47));
	printf("%d\n", ft_isalnum(48));
	printf("%d\n", isalnum(48));
	printf("%d\n", ft_isalnum(57));
	printf("%d\n", isalnum(57));
	printf("%d\n", ft_isalnum(59));
	printf("%d\n", isalnum(59));
	printf("%d\n", ft_isalnum(' '));
	printf("%d\n", isalnum(' '));
	printf("%d\n", ft_isalnum('.'));
	printf("%d\n", isalnum('.'));
	printf("%d\n", ft_isalnum('9'));
	printf("%d\n", isalnum('9'));
	printf("%d\n", ft_isalnum('a'));
	printf("%d\n", isalnum('a'));
	printf("%d\n", ft_isalnum('M'));
	printf("%d\n", isalnum('M'));
	printf("%d\n", ft_isalnum(1000));
	printf("%d\n", isalnum(1000));
	printf("%d\n", ft_isalnum(-100));
	printf("%d\n", isalnum(-100));
	return (0);
}*/
