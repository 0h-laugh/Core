/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:25:29 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/17 15:51:41 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int ac, char **av)
{
	//Declare pointers to two data structs, one 'a' and one 'b'
	t_stack stack_a;
	t_stack stack_b;

	//Set them both to NULL to avoid undefined behaviour
	stack_a.top = NULL;
	stack_b.top = NULL;

	//Check input count and if its empty
		//If less than 2 return Error

	//handle both cases of input - normal arguments and string
		//if string use split to split into substrings

	//Initalize stack_a
		//Handle all errors, check duplicates, etc
			//in case of any free a and return error

	//Check if each input is long int
		//if not convert

	//Append nodes into stack_a
	fill_stack(ac, av, &stack_a);

	//Check if its sorted
		//if not - sort by alghoritm
			// if only 2 numbers
				//swap
			// if 3 numbers
				//sort_three
			// if more than 3 numbers
				//turk algorithm

	//Clean up the stack

	//Temporary print
	t_node *current_a = stack_a.top;
	t_node *current_b = stack_b.top;
	while (current_a != NULL || current_b != NULL)
	{
		if (current_a != NULL)
		{
			printf("%d", current_a->data);
			current_a = current_a->next;
		}
		printf("\t");
		if (current_b != NULL)
		{
			printf("%d", current_b->data);
			current_b = current_b->next;
		}
		printf("\n");
	}
	printf("_\t_\n");
	printf("a\tb\n");
	return (0);
}
