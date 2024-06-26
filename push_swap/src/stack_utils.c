/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/26 20:41:37 by ojastrze         ###   ########.fr       */
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

int	parse_single_arg(char *arg, int *numbers, int num_count)
{
	char	**split_args;
	int		i;

	split_args = ft_split(arg, ' ');
	i = 0;
	while (split_args[i])
	{
		if (!ft_isnumber(split_args[i]) || ft_atol(split_args[i]) > INT_MAX
			|| ft_atol(split_args[i]) < INT_MIN)
		{
			free(numbers);
			ft_error();
		}
		numbers[num_count] = ft_atoi(split_args[i]);
		if (num_count != 0 && ft_check_dup(numbers, num_count, numbers[num_count]))
		{
			free(numbers);
			ft_error();
		}
		num_count++;
		i++;
	}
	ft_free_split(split_args);
	return (num_count);
}

int	*parse_args(int argc, char **argv)
{
	int	*numbers;
	int	i;
	int j;
	int num_count;
	int total_args;
	char **split_args;

	total_args = 0;
	i = 1;
	while (i < argc) {
		split_args = ft_split(argv[i], ' ');
		j = 0;
		while (split_args[j]) {
			total_args++;
			j++;
		}
		ft_free_split(split_args);
		i++;
	}

	numbers = allocate_numbers(total_args);
	i = 1;
	num_count = 0;
	while (i < argc) {
		split_args = ft_split(argv[i], ' ');
		j = 0;
		while (split_args[j])
		{
			if (!ft_isnumber(split_args[j]) || ft_atol(split_args[j]) > INT_MAX
				|| ft_atol(split_args[j]) < INT_MIN)
			{
				free(numbers);
				ft_error();
			}
			numbers[num_count] = ft_atoi(split_args[j]);
			if (num_count != 0 && ft_check_dup(numbers, num_count, numbers[num_count]))
			{
				free(numbers);
				ft_error();
			}
			num_count++;
			j++;
		}
		ft_free_split(split_args);
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
