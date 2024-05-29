/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:44:34 by ojastrze          #+#    #+#             */
/*   Updated: 2024/05/29 14:40:10 by ojastrze         ###   ########.fr       */
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

void	rotate(t_stack **stack)
{
	t_node	*current;

	if (stack_a->next == NULL || stack_a->prev->next == NULL)
		return ;
	current = stack_a->next;
	while (current->next != NULL)
		current = current->next;
	current->next = stack_a->prev;
	stack_a->next = stack_a->prev->next;
	current->prev->next = NULL;
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
