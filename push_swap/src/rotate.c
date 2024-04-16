/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:44:34 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/16 16:20:45 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
*/

void	rotate_a(t_stack *stack_a)
{
	t_node	*current;

	if (stack_a->top == NULL || stack_a->top->next == NULL)
		return ;
	current = stack_a->top;
	while (current->next != NULL)
		current = current->next;
	current->next = stack_a->top;
	stack_a->top = stack_a->top->next;
	current->next->next = NULL;
}

void	rotate_b(t_stack *stack_b)
{
	t_node	*current;

	if (stack_b->top == NULL || stack_b->top->next == NULL)
		return ;
	current = stack_b->top;
	while (current->next != NULL)
		current = current->next;
	current->next = stack_b->top;
	stack_b->top = stack_b->top->next;
	current->next->next = NULL;
}

void	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
