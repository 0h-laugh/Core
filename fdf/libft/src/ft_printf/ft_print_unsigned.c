/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:08:32 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/21 19:08:49 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned int u, int *len)
{
	if (u >= 10)
		ft_print_unsigned(u / 10, len);
	ft_print_char(u % 10 + '0', len);
}
