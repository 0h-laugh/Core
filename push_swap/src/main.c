/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/07/02 14:45:19 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*numbers;
	size_t 	size;

	stack_a = NULL;
	stack_b = NULL;
	numbers = parse_args(argc, argv);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		size = ft_strlen(argv[1]) / 2 + 1;
	else
		size = argc - 1;
	stack_a = init_stack(numbers, size);
	if (!stack_a)
	{
		free(numbers);
		ft_error();
	}
	print_stacks(stack_a, stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	free(numbers);
	return (0);
}
