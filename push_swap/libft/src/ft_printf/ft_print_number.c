/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:59:16 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/21 19:00:16 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_number(int number, int *len)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	else if (number < 0)
	{
		ft_print_char('-', len);
		ft_print_number(-number, len);
	}
	else
	{
		if (number > 9)
			ft_print_number(number / 10, len);
		ft_print_char(number % 10 + '0', len);
	}
}
