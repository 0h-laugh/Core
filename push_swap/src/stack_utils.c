/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/21 20:41:11 by ojastrze         ###   ########.fr       */
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

int	*parse_string_args(char *arg)
{
	char	**split_args;
	int		*numbers;
	int		i;
	int		len;

	split_args = ft_split(arg, ' ');
	len = 0;
	while (split_args[len])
		len++;
	numbers = allocate_numbers(len + 1);
	i = 0;
	while (i < len)
	{
		if (!ft_isnumber(split_args[i]) || ft_atol(split_args[i]) > INT_MAX
			|| ft_atol(split_args[i]) < INT_MIN)
		{
			free(numbers);
			ft_error();
		}
		numbers[i] = ft_atoi(split_args[i]);
		if (i != 0 && ft_check_dup(numbers, i, numbers[i]))
		{
			free(numbers);
			ft_error();
		}
		i++;
	}
	ft_free_split(split_args);
	return (numbers);
}

int	*parse_args(int argc, char **argv)
{
	int	*numbers;
	int	i;

	i = 0;
	if (argc < 2)
		ft_error();
	if (argc == 2 && ft_strchr(argv[1], ' '))
		return (parse_string_args(argv[1]));
	numbers = allocate_numbers(argc);
	while (++i < argc)
	{
		if (!ft_isnumber(argv[i]) || ft_atol(argv[i]) > INT_MAX
			|| ft_atol(argv[i]) < INT_MIN)
		{
			free(numbers);
			ft_error();
		}
		numbers[i - 1] = ft_atoi(argv[i]);
		if (i != 1 && ft_check_dup(numbers, i - 1, numbers[i - 1]))
		{
			free(numbers);
			ft_error();
		}
	}
	return (numbers);
}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		ft_printf("%d\n", *(int *)current->content);
		current = current->next;
	}
}
