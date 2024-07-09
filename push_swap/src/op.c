/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@stundent.42warsaw.pl>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:10:43 by ojastrze          #+#    #+#             */
/*   Updated: 2024/07/09 13:10:48 by ojastrze         ###   ########.fr       */
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