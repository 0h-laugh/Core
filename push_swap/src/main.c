/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:46:40 by olaf              #+#    #+#             */
/*   Updated: 2024/09/22 18:39:11 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
    t_stack	*stack_a;
    t_stack	*stack_b;
    int		size;

    if (ac < 2)
        return (0);
    if (!input_check(av))
        ft_error(NULL, NULL);
    stack_a = fill_with_values(ac, av);
    stack_b = NULL;
    size = get_stack_size(stack_a);
    assign_index(stack_a, size + 1);
    if (size == 2 && !ft_issorted(stack_a))
        sa(&stack_a);
    else if (size == 3)
        tiny_sort(&stack_a);
    else if (size > 3 && !ft_issorted(stack_a))
        turk_sort(&stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}