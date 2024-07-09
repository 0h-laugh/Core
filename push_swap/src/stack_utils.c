/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/07/04 21:18:13 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*init_node(int number)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		ft_error();
	new_node->content = malloc(sizeof(int));
	if (!new_node->content)
	{
		free(new_node);
		ft_error();
	}
	*(int *)(new_node->content) = number;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*init_one(char *arg, t_stack *stack_a, int i)
{
	char        **split_args;
	int         j;
	long int	number;

	split_args = ft_split(arg, ' ');
	j = 0;
	while (split_args[j])
	{
		number = ft_atoi(split_args[j]);
		if (number > INT_MAX || number < INT_MIN)
			ft_error();
		if (i == 1 && j == 0)
			stack_a = init_node((int)number);
		else
			ft_lstadd_back(&stack_a, init_node((int)number));
		free(split_args[j]);
		j++;
	}
	free(split_args);
	return (stack_a);
}

t_stack	*init_separate(char *arg, t_stack *stack_a, int i)
{
	long int	number;

	number = ft_atoi(arg);
	if (number > INT_MAX || number < INT_MIN)
		ft_error();
	if (i == 1)
		stack_a = init_node((int)number);
	else
		ft_lstadd_back(&stack_a, init_node((int)number));
	return (stack_a);
}

//This function checks if stack is sorted
int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)(stack->content) > *(int *)(stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = stack_a;
	current_b = stack_b;
	ft_printf("Stack A\tStack B\n");
	while (current_a != NULL || current_b != NULL)
	{
		if (current_a != NULL)
		{
			ft_printf("%d\t", *(int *)current_a->content);
			current_a = current_a->next;
		}
		else
			ft_printf(" \t");

		if (current_b != NULL)
		{
			ft_printf("%d\n", *(int *)current_b->content);
			current_b = current_b->next;
		}
		else
			ft_printf(" \n");
	}
}
