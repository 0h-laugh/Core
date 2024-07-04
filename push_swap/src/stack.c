/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@stundent.42warsaw.pl>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:19:55 by ojastrze          #+#    #+#             */
/*   Updated: 2024/07/04 21:15:10 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*init_stack(int ac, char **av)
{
	t_stack		*stack_a;
	int			i;

	stack_a = NULL;
	i = 1;
	while (i < ac) {
		if (ft_strchr(av[i], ' '))
			stack_a = init_one(av[i], stack_a, i);
		else
			stack_a = init_separate(av[i], stack_a, i);
		i++;
	}
	return (stack_a);
}
