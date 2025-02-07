/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:57:21 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/21 18:59:00 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int x, int *len, char x_x)
{
	char	string[25];
	char	*base_char;
	int		i;

	if (x_x == 'X')
		base_char = "0123456789ABCDEF";
	else
		base_char = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_print_char('0', len);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_char[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_print_char(string[i], len);
}
