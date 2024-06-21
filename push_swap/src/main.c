/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/21 19:19:40 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	int	*numbers;
	int i;

	i = 1;
	if (argc < 2)
	{
		ft_error();
	}
	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
	{
		ft_error();
	}
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]) || ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
		{
			free(numbers);
			ft_error();
		}
		numbers[i - 1] = ft_atoi(argv[i]);
		if (i != 1 && ft_check_dup(numbers, i - 1, numbers[i - 1]))
		{
			free(numbers);
			ft_error();
		}
		i++;
	}
	// Initialize the stack with the input numbers
	stack_a = init_stack(numbers, argc - 1);
	if (!stack_a)
	{
		free(numbers);
		ft_error();
	}
	// Print the stack
	print_stack(stack_a);
	print_stack(stack_b);
	// Free the stack and the numbers array when you're done with them
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	free(numbers);
	return 0;
}