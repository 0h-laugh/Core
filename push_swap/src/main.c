/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/07/04 21:16:20 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int     *numbers;
	int     num_count = 0;
	int     i;

	if (ac == 1)
		return (0);
	numbers = malloc(sizeof(int) * ac);
	if (!numbers)
		ft_error();
	i = 1;
	while (i < ac)
	{
		num_count = input_check(av[i], numbers, num_count);
		i++;
	}
	stack_a = init_stack(ac, av);
	if (!stack_a)
	{
		free(numbers);
		ft_error();
	}
	stack_b = NULL;
	print_stacks(stack_a, stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	free(stack_a);
	free(numbers);
	return (0);
}
