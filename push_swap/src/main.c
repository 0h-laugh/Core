/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/21 19:37:44 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	int	*numbers;

	numbers = parse_args(argc, argv);
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