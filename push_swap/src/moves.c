/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:19:48 by olaf              #+#    #+#             */
/*   Updated: 2024/09/22 18:28:09 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Reverse rotates both stacks until cost is 0*/

static void	do_rrr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        (*cost_a)++;
        (*cost_b)++;
        rrr(a, b);
    }
}

/* Rotates both stacks until cost is 0*/

static void	do_rr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        (*cost_a)--;
        (*cost_b)--;
        rr(a, b);
    }
}

/* Rotates stack_a until cost is 0 */

static void	do_ra(t_stack **a, int *cost)
{
    while (*cost)
    {
        if (*cost > 0)
        {
            ra(a);
            (*cost)--;
        }
        else if (*cost < 0)
        {
            rra(a);
            (*cost)++;
        }
    }
}

/* Rotates stack_b until cost is 0 */

static void	do_rb(t_stack **b, int *cost)
{
    while (*cost)
    {
        if (*cost > 0)
        {
            rb(b);
            (*cost)--;
        }
        else if (*cost < 0)
        {
            rrb(b);
            (*cost)++;
        }
    }
}

/* Compares costs and rotates best, then pushes top element of stack_b to stack_a */

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    if (cost_a < 0 && cost_b < 0)
        do_rrr(a, b, &cost_a, &cost_b);
    else if (cost_a > 0 && cost_b > 0)
        do_rr(a, b, &cost_a, &cost_b);
    do_ra(a, &cost_a);
    do_rb(b, &cost_b);
    pa(a, b);
}