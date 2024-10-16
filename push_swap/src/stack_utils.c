/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:44:20 by olaf              #+#    #+#             */
/*   Updated: 2024/09/22 19:11:46 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Returns last element of stack */

t_stack	*ft_stack_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* Returns pre-last element of stack */

t_stack	*ft_stack_before_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/* Adds element to the bottom of stack */

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = ft_stack_last(*stack);
	tail->next = new;
}

/* Returns size of stack */

int	get_stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

/* Assign index to each value in stack from highest to lowest*/

void	assign_index(t_stack *stack_a, int size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		data;

	while (--size > 0)
	{
		ptr = stack_a;
		data = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->data == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->data > data && ptr->index == 0)
			{
				data = ptr->data;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}
