/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/28 21:30:05 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//This function checks if a given string is a number.
int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

//This function converts a string to a long integer for MAX_INT and MIN_INT
long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	ft_check_dup(int *numbers, int size, int number)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (numbers[i] == number)
			return (1);
		i++;
	}
	return (0);
}

void	ft_error(void)
{
	ft_printf("Error\n");
	exit (1);
}

int	input_check(char *arg, int *numbers, int num_count)
{
	if (!ft_isnumber(arg) || ft_atol(arg) > INT_MAX || ft_atol(arg) < INT_MIN)
	{
		free(numbers);
		ft_error();
	}
	numbers[num_count] = ft_atoi(arg);
	if (num_count != 0 && ft_check_dup(numbers, num_count, numbers[num_count]))
	{
		free(numbers);
		ft_error();
	}
	return (num_count + 1);
}