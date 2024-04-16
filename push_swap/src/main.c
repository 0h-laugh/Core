/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:25:29 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/16 16:16:05 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int ac, char **av)
{
	//Declare and initalize stack
	t_stack stack_a;
	t_stack stack_b;

	stack_a.top = NULL;
	stack_b.top = NULL;

	//take input and put it into stack
	fill_stack(ac, av, &stack_a);

	//Sort
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	reverse_rotate_ab(&stack_a, &stack_b);
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
	//Output of instructions/stack
	return (0);
}
