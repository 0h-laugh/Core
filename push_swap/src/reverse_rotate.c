/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:06:31 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/16 16:15:30 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.
*/

void	reverse_rotate_a(t_stack *stack_a)
{
	t_node	*current;
	t_node	*last;

	if (stack_a->top == NULL || stack_a->top->next == NULL)
		return ;
	current = stack_a->top;
	while (current->next->next != NULL)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = stack_a->top;
	stack_a->top = last;
}

void	reverse_rotate_b(t_stack *stack_b)
{
	t_node	*current;
	t_node	*last;

	if (stack_b->top == NULL || stack_b->top->next == NULL)
		return ;
	current = stack_b->top;
	while (current->next->next != NULL)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = stack_b->top;
	stack_b->top = last;
}

void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
