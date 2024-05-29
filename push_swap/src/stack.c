/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:55:17 by ojastrze          #+#    #+#             */
/*   Updated: 2024/05/29 17:00:52 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stack(t_stack **stack, char **av)
{
	int i;
	int value;
	t_stack *new_node;
	i = 0;
	while (av[i]) {
		value = ft_atoi(av[i]);
		new_node = create_new_node(value);
		if (!new_node)
			//error handling
			return;
		if (!check_input(char **av))
		{
			//error handling
			return;
		}
		i++;
	}
	add_new_node(**stack)
}