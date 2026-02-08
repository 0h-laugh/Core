/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:05:17 by ojastrze          #+#    #+#             */
/*   Updated: 2024/03/21 19:41:47 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(const char *string, ...);

void	ft_print_char(char c, int *len);
void	ft_print_string(char *args, int *len);

void	ft_print_number(int number, int *len);
void	ft_print_unsigned(unsigned int u, int *len);
void	ft_print_pointer(size_t pointer, int *len);

void	ft_print_hex(unsigned int x, int *len, char x_x);

#endif
