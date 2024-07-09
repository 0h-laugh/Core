/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/07/08 18:30:52 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int count_numbers(int ac, char **av)
{
	int count = 0;
	int i;
	char **split_args;

	for (i = 1; i < ac; i++)
	{
		split_args = ft_split(av[i], ' ');
		for (int j = 0; split_args[j]; j++, count++);
		free_split_args(split_args);
	}
	return count;
}

void free_split_args(char **split_args)
{
	int i = 0;
	while (split_args[i])
		free(split_args[i++]);
	free(split_args);
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b = NULL;
	int num_count = 0;
	int total_numbers, i;
	int *numbers;

	if (ac == 1)
		return (0);
	total_numbers = count_numbers(ac, av);
	numbers = (int *)malloc(sizeof(int) * total_numbers);
	if (!numbers)
		ft_error();
	for (i = 1; i < ac; i++)
		num_count = input_check(av[i], numbers, num_count);
	stack_a = init_stack(ac, av);
	if (!stack_a)
	{
		free(numbers);
		ft_error();
	}
	print_stacks(stack_a, stack_b);
	quick_sort(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	free(numbers);
	return (0);
}
