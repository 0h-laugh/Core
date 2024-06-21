/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/21 18:45:53 by ojastrze         ###   ########.fr       */
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
			ft_error();
			return NULL;
		}
		*p = numbers[i];
		new_node = ft_lstnew(p);
		if (!new_node)
		{
			ft_error();
			return NULL;
		}
		ft_lstadd_back(&stack, new_node);
		i++;
	}
	return stack;
}

int *parse_args(int argc, char **argv)
{
	int *numbers;
	int i;

	i = 1;
	if (argc < 2)
		ft_error();
	numbers = malloc (sizeof(int) * (argc - 1));
	if (!numbers)
		ft_error();
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]) || ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
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
		i++;
	}
	return numbers;
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

void	ft_error(void)
{
	ft_printf("Error\n");
	exit (1);
}