/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:35:47 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/04 18:44:33 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int num_cmp(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1 == s2)
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

static int check_duplicates(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && num_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int is_number(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '+' || av[i] == '-' && av[i + 1] != '\0')
		i++;
	while (av[i] && av[i] >= 0 && av[i] <= 9)
		i++;
	if (av[i] != '\0' && av[i] < 0 || av[i] > 9)
		return (0);
	return (1);
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