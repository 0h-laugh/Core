/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:54:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/07 13:37:18 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	return (0);
}
/*

#include <stdio.h>
#include <ctype.h>

int	main()
{
	printf("%d\n", ft_isalpha(0));
	printf("%d\n", isalpha(0));
	printf("%d\n", ft_isalpha(65));
	printf("%d\n", isalpha(65));
	printf("%d\n", ft_isalpha(69));
	printf("%d\n", isalpha(69));
	printf("%d\n", ft_isalpha(255));
	printf("%d\n", isalpha(255));
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", isalpha('a'));
	printf("%d\n", ft_isalpha('Z'));
	printf("%d\n", isalpha('Z'));
	printf("%d\n", ft_isalpha(' '));
	printf("%d\n", isalpha(' '));
	printf("%d\n", ft_isalpha('*'));
	printf("%d\n", isalpha('*'));
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n", isalpha('1'));
	printf("%d\n", ft_isalpha('.'));
	printf("%d\n", isalpha('.'));
	return (0);
}*/
