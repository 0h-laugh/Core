/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:07:11 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/12 22:17:36 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	fill_stack(int ac, char **av, t_stack *stack_a)
{
	int i;
	int value;

	i = 1;
	if (ac < 2)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	while (i < ac)
	{
		value = atoi(av[i]);
		create_node(stack_a, value);
		i++;
	}
}