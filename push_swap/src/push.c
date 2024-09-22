/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:52:31 by olaf              #+#    #+#             */
/*   Updated: 2024/09/22 15:13:11 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* General push - pushes top element of src stack to the top of dst stack*/

static void push(t_stack **src, t_stack **dst)
{
    t_stack *tmp;

    if (*src == NULL)
        return ;
    tmp = (*src)->next;
    (*src)->next = *dst;
    *dst = *src;
    *src = tmp;
}

/* Pushes top element of stack_b to stack_a and prints "pa" */

void    pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    ft_putstr_fd("pa\n", 1);
}

/* Pushes top element of stack_a to stack_b and prints "pb" */

void    pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    ft_putstr_fd("pb\n", 1);
}
