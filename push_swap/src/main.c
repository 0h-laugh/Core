/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/21 20:24:33 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*numbers;

	stack_a = NULL;
	stack_b = NULL;
	numbers = parse_args(argc, argv);
	stack_a = init_stack(numbers, argc - 1);
	if (!stack_a)
	{
		free(numbers);
		ft_error();
	}
	print_stack(stack_a);
	print_stack(stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	free(numbers);
	return (0);
}
