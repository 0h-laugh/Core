/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:32:46 by olaf              #+#    #+#             */
/*   Updated: 2024/09/22 19:09:21 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* General reverse rotate - Bottom element of stack is sent to the top */

static void reverse_rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;
    t_stack *before_tail;

    tail = ft_stack_last(*stack);
    before_tail = ft_stack_before_last(*stack);
    tmp = *stack;
    *stack = tail;
    (*stack)->next = tmp;
    before_tail->next = NULL;
}

/* Swap top 2 elements of stack_a and prints "rra" */

void    rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    ft_putstr_fd("rra\n", 1);
}

/* Swap top 2 elements of stack_b and prints "rrb" */

void    rrb(t_stack **stack_b)
{
    reverse_rotate(stack_b);
    ft_putstr_fd("rrb\n", 1);
}

/* Reverse rotates both stacks and prints "rrr" */

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    ft_putstr_fd("rrr\n", 1);
}
