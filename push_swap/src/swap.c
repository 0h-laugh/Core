/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:22:37 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/16 15:40:43 by ojastrze         ###   ########.fr       */
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

void	swap_a(t_stack *stack_a)
{
	int	temp;

	if (stack_a->top == NULL || stack_a->top->next == NULL)
		return ;
	temp = stack_a->top->data;
	stack_a->top->data = stack_a->top->next->data;
	stack_a->top->next->data = temp;
}

void	swap_b(t_stack *stack_b)
{
	int	temp;

	if (stack_b->top == NULL || stack_b->top->next == NULL)
		return ;
	temp = stack_b->top->data;
	stack_b->top->data = stack_b->top->next->data;
	stack_b->top->next->data = temp;
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
