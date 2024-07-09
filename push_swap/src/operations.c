/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:56:20 by ojastrze          #+#    #+#             */
/*   Updated: 2024/07/08 18:38:18 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void swap(t_stack **stack)
{
	t_stack *temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		temp->next = *stack;
		*stack = temp;
	}
}
void push(t_stack **src, t_stack **dst)
{
	if (*src)
	{
		t_stack *temp = *src;
		*src = (*src)->next;
		temp->next = *dst;
		*dst = temp;
	}
}

void rotate(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		t_stack *temp = *stack;
		*stack = (*stack)->next;
		ft_lstadd_back(stack, temp);
		temp->next = NULL;
	}
}

void reverse_rotate(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		t_stack *last = ft_lstlast(*stack);
		t_stack *prev = *stack;
		while (prev->next != last)
			prev = prev->next;
		prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}