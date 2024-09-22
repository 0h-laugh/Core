/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:06:20 by olaf              #+#    #+#             */
/*   Updated: 2024/09/22 16:24:44 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Frees every element of stack and sets pointer to null */

void    free_stack(t_stack **stack)
{
    t_stack	*tmp;

    if (!stack || !(*stack))
        return ;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
    *stack = NULL;
}

/* Frees both stacks, writes error and exits*/

void	ft_error(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_a == NULL || *stack_a != NULL)
        free_stack(stack_a);
    if (stack_b == NULL || *stack_b != NULL)
        free_stack(stack_b);
    write(2, "Error\n", 6);
    exit (1);
}

/* Returns absolute value of given number */

int ft_abs_nbr(int nbr)
{
    if (nbr < 0)
        return (nbr * -1);
    return (nbr);
}

/* Checks if char is + or - */

int	ft_issign(char c)
{
    return (c == '+' || c == '-');
}

/* Compares two strings of digits if they are the same*/

int	nbstr_cmp(const char *s1, const char *s2)
{
    int	i;
    int	j;

    i = 0;
    j = i;
    if (s1[i] == '+')
    {
        if (s2[j] != '+')
            i++;
    }
    else
    {
        if (s2[j] == '+')
            j++;
    }
    while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
    {
        i++;
        j++;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}