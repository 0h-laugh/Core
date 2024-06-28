/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/28 21:35:51 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*init_stack(int *numbers, int size)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;
	int		*p;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		p = malloc(sizeof(int));
		if (!p)
			ft_error();
		*p = numbers[i];
		new_node = ft_lstnew(p);
		if (!new_node)
			ft_error();
		ft_lstadd_back(&stack, new_node);
		i++;
	}
	return (stack);
}

int	*allocate_numbers(int argc)
{
	int	*numbers;

	if (argc < 2)
		ft_error();
	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		ft_error();
	return (numbers);
}

int	*parse_args(int argc, char **argv)
{
	int		*numbers;
	int		i;
	int		num_count;
	char	**split_args;

	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		split_args = ft_split(argv[1], ' ');
		i = 0;
		while (split_args[i])
			i++;
		numbers = allocate_numbers(i);
		i = 0;
		num_count = 0;
		while (split_args[i])
		{
			num_count = input_check(split_args[i], numbers, num_count);
			i++;
		}
		free(split_args);
	}
	else
	{
		numbers = allocate_numbers(argc);
		i = 1;
		num_count = 0;
		while (i < argc)
		{
			num_count = input_check(argv[i], numbers, num_count);
			i++;
		}
	}
	return (numbers);
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
