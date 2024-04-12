/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:09:33 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/12 22:10:11 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	create_node(t_stack *stack, int value)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		printf("Allocation Error\n" );
		exit(EXIT_FAILURE);
	}
	new_node->data = value;
	new_node->next = stack->top;
	stack->top = new_node;
}