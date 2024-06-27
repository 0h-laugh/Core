/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/27 09:03:27 by ojastrze         ###   ########.fr       */
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
	int	*numbers;
	int	i;
	int num_count;

	numbers = allocate_numbers(argc);
	i = 1;
	num_count = 0;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]) || ft_atol(argv[i]) > INT_MAX
			|| ft_atol(argv[i]) < INT_MIN)
		{
				free(numbers);
				ft_error();
		}
		numbers[num_count] = ft_atoi(argv[i]);
		if (num_count != 0 && ft_check_dup(numbers, num_count, numbers[num_count]))
		{
			free(numbers);
			ft_error();
		}
		num_count++;
		i++;
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
