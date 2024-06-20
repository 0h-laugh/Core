/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/20 23:04:05 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*init_stack(int *numbers, int size)
{
	t_stack *stack = NULL;
	t_stack *new_node;
	int i;
	int *p;

	i = 0;
	while (i < size)
	{
		p = malloc(sizeof(int));
		if (!p)
		{
			//handle error
			return NULL;
		}
		*p = numbers[i];
		new_node = ft_lstnew(p);
		if (!new_node)
		{
			//handle error
			return NULL;
		}
		ft_lstadd_back(&stack, new_node);
		i++;
	}
	return stack;
}

void	print_stack(t_stack *stack)
{
	t_stack *current;
	current = stack;
	while (current != NULL)
	{
		ft_printf("%d\n", *(int *)current->content);
		current = current->next;
	}
}