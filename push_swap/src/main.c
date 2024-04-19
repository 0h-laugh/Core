/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:25:29 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/19 12:09:52 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int ac, char **av)
{
	//Declare pointers to two data structs, one 'a' and one 'b'
	t_stack *stack_a;
	t_stack *stack_b;

	//Set them both to NULL to avoid undefined behaviour
	stack_a = NULL;
	stack_b = NULL;

	//Check input count and if its empty
		//If less than 2 return Error
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (1);

	//handle both cases of input - normal arguments and string
		//if string use split to split into substrings
	else if (ac == 2)
		av = ft_split(av[1], ' ');

	//Initalize stack_a
		//Handle all errors, check duplicates, etc
			//in case of any free a and return error
	init_stack(&stack_a, (av + 1));

	//Check if each input is long int
		//if not convert

	//Append nodes into stack_a


	//Check if its sorted
		//if not - sort by alghoritm
			// if only 2 numbers
				//swap
			// if 3 numbers
				//sort_three
			// if more than 3 numbers
				//turk algorithm
	if (!is_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			swap_a(&stack_a);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			turk_sort(&stack_a, &stack_b);
	}

	//Clean up the stack
	ft_free(&stack_a);
	return (0);
}
