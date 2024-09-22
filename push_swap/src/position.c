/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:05:06 by olaf              #+#    #+#             */
/*   Updated: 2024/09/22 19:08:32 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Assigns position for every element in stack from top to bottom in ascending order */

static void get_position(t_stack **stack)
{
    t_stack *tmp;
    int     i;

    tmp = *stack;
    i = 0;
    while (tmp)
    {
        tmp->position = i;
        tmp = tmp->next;
        i++;
    }
}

/* Looks for best targer position in stack_a for given index of element in stack_b */

static int  get_target(t_stack **stack_a, int index, int tar_index, int tar_pos)
{
    t_stack *tmp_a;

    tmp_a = *stack_a;
    while (tmp_a)
    {
        if (tmp_a->index > index && tmp_a->index < tar_index)
        {
            tar_index = tmp_a->index;
            tar_pos = tmp_a->position;
        }
        tmp_a = tmp_a->next;
    }
    if (tar_index != INT_MAX)
        return (tar_pos);
    tmp_a = *stack_a;
    while (tmp_a)
    {
        if (tmp_a->index < tar_index)
        {
            tar_index = tmp_a->index;
            tar_pos = tmp_a->position;
        }
        tmp_a = tmp_a->next;
    }
    return (tar_pos);
}

/* Gets position of value with lowest index in stack */

int get_lowest_index_position(t_stack **stack)
{
    t_stack *tmp;
    int     lowest_index;
    int     lowest_pos;

    tmp = *stack;
    lowest_index = INT_MAX;
    get_position(stack);
    lowest_pos = tmp->position;
    while (tmp)
    {
        if (tmp->index < lowest_index)
        {
            lowest_index = tmp->index;
            lowest_pos = tmp->position;
        }
        tmp = tmp->next;
    }
    return (lowest_pos);
}

/* Assigns target position in stack_a for it's every element for cost calculation */

void    get_target_position(t_stack **a, t_stack **b)
{
    t_stack *tmp_b;
    int     target_pos;

    tmp_b = *b;
    get_position(a);
    get_position(b);
    target_pos = 0;
    while (tmp_b)
    {
        target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
        tmp_b->target = target_pos;
        tmp_b = tmp_b->next;
    }
}