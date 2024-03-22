/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:00:29 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/22 12:18:41 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_signcheck(char s, va_list *args, int *len, int *i)
{
	if (s == 'c')
		ft_print_char(va_arg(*args, int), len);
	else if (s == 's')
		ft_print_string(va_arg(*args, char *), len);
	else if (s == 'p')
		ft_print_pointer(va_arg(*args, size_t), len);
	else if (s == 'd' || s == 'i')
		ft_print_number(va_arg(*args, int), len);
	else if (s == 'u')
		ft_print_unsigned(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_print_hex(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_print_hex(va_arg(*args, unsigned int), len, 'X');
	else if (s == '%')
		ft_print_char('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_signcheck(string[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_print_char((char)string[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
