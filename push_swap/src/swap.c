/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:48:23 by olaf              #+#    #+#             */
/*   Updated: 2024/09/22 19:12:03 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* General swap - swaps 2 elements on top of the stack (if present) */

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

/* Swap top 2 elements of stack_a and prints "sa" */

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr_fd("sa\n", 1);
}

/* Swap top 2 elements of stack_b and prints "sb" */

void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr_fd("sb\n", 1);
}

/* Swap top elements of stack_a and top elements of stack_b, prints "ss" */

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr_fd("ss\n", 1);
}
