/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:22:37 by ojastrze          #+#    #+#             */
/*   Updated: 2024/05/25 14:21:21 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
*/

void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || *stack->next == NULL)
		return ;
	temp = *stack;
	*stack = *stack->next;
	temp->next = *stack->next;
	*stack->next = temp;
	if (temp->next != NULL)
		temp->next->prev = temp;
	temp->prev = *stack;
	*stack->prev = NULL;
}



void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
