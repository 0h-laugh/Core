/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:03:39 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/21 19:59:52 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(size_t pointer, int *len)
{
	char	string[25];
	char	*base_char;
	int		i;

	i = 0;
	base_char = "0123456789abcdef";
	write(1, "0x", 2);
	(*len) += 2;
	if (pointer == 0)
	{
		ft_print_string("(nill)", len);
		return ;
	}
	while (pointer != 0)
	{
		string[i] = base_char[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
		ft_print_char(string[i], len);
}
