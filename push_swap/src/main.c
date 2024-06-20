/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/20 23:06:08 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	// Check if there are enough arguments
	if (argc < 2)
	{
		ft_putstr_fd("Error: Not enough arguments\n", 2);
		return 1;
	}

	// Convert argv to an array of integers
	int *numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
	{
		ft_putstr_fd("Error: Malloc failed\n", 2);
		return 1;
	}
	int i = 1;
	while (i < argc)
	{
		numbers[i - 1] = ft_atoi(argv[i]);
		i++;
	}

	// Initialize the stack with the input numbers
	t_stack *stack = init_stack(numbers, argc - 1);
	if (!stack)
	{
		ft_putstr_fd("Error: Stack initialization failed\n", 2);
		free(numbers);
		return 1;
	}

	// Print the stack
	print_stack(stack);

	// Free the stack and the numbers array when you're done with them
	ft_lstclear(&stack, free);
	free(numbers);

	return 0;
}