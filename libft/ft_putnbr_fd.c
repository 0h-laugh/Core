/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:53:42 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/08 19:56:24 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n == 0)
		ft_putchar_fd('0', fd);
	else
		ft_putchar_fd(n + '0', fd);
}
/*
#include "libft.h"
#include <unistd.h>

int main(void)
{
    int min_int = -214748;
    int max_int = 2147483647;
    int zero = 0;

    // Test dla minimalnej wartości int
    ft_putnbr_fd(min_int, 1); // Przekierowanie wyjścia na standardowe wyjście
    ft_putchar_fd('\n', 1); // Nowa linia dla czytelności

    // Test dla maksymalnej wartości int
    ft_putnbr_fd(max_int, 1);
    ft_putchar_fd('\n', 1);

    // Test dla zera
    ft_putnbr_fd(zero, 1);
    ft_putchar_fd('\n', 1);

    return (0);
}*/
