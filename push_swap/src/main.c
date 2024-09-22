/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:46:40 by olaf              #+#    #+#             */
/*   Updated: 2024/09/22 19:31:35 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char    **split_args(int ac, char **av, int *new_ac)
{
    char    **args;

    if (ac == 2)
    {
        args = ft_split(av[1], ' ');
        *new_ac = 0;
        while (args[*new_ac])
            (*new_ac)++;
    }
    else
    {
        args = av + 1;
        *new_ac = ac - 1;
    }
    return (args);
}

static void free_split(char **args, int ac, char **av)
{
    int i;

    if (args != av + 1)
    {
        i = 0;
        while (i < ac)
            free(args[i++]);
        free(args);
    }
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int stack_size;
    char **args;

    args = split_args(ac, av, &ac);
    if (ac < 2)
        return (0);
    if (!input_check(args))
        ft_error(NULL, NULL);
    stack_b = NULL;
    stack_a = fill_with_values(ac, args);
    stack_size = get_stack_size(stack_a);
    assign_index(stack_a, stack_size + 1);
    if (stack_size == 2 && !ft_issorted(stack_a))
        sa(&stack_a);
    else if (stack_size == 3)
        tiny_sort(&stack_a);
    else if (stack_size > 3 && !ft_issorted(stack_a))
        turk_sort(&stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    free_split(args, ac, av);
    return (0);
}