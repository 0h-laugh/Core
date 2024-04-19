/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:35:47 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/17 19:45:43 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int check_duplicates(char **av)
{
	
}

static int is_zero(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '+' || av[i] == '-')
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	check_input(char **av)
{
	int i;
	int zeros;

	i = 1;
	zeros = 0;
	while (av[i])
	{
		if (is_number(av[i]) == 0)
			return (0);
		zeros += is_zero(av[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	if (check_duplicates(av) == 0)
		return (0);
	return (1);
}