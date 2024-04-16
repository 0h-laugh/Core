/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:44:23 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/16 15:43:42 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
*/

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b->top == NULL)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	temp->next = stack_a->top;
	stack_a->top = temp;
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_a->top == NULL)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	temp->next = stack_b->top;
	stack_b->top = temp;
}
