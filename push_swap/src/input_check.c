/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:33:11 by olaf              #+#    #+#             */
/*   Updated: 2024/09/22 19:07:07 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Checks if provided arg is valid number */

static int  is_number(char *av)
{
    int i;

    i = 0;
    if (ft_issign(av[i]) && av[i + 1] != '\0')
        i++;
    while (av[i] && ft_isdigit(av[i]))
        i++;
    if (av[i] != '\0' && !ft_isdigit(av[i]))
        return (0);
    return (1);
}

/* Checks for duplicates */

static int  is_duplicate(char **av)
{
    int i;
    int j;

    i = 1;
    while (av[i])
    {
        j = 1;
        while (av[j])
        {
            if (j != i && nbstr_cmp(av[i], av[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

/* Checks if arg is 0 */

static int  is_zero(char *av)
{
    int i;

    i = 0;
    if (ft_issign(av[i]))
        i++;
    while (av[i] && av[i] == '0')
        i++;
    if (av[i] != '\0')
        return (0);
    return (1);
}

int ft_issorted(t_stack *stack)
{
    while (stack->next != NULL)
    {
        if (stack->data > stack->next->data)
            return (0);
        stack = stack->next;
    }
    return (1);
}

int input_check(char **av)
{
    int i;
    int nb_zeros;

    nb_zeros = 0;
    i = 1;
    while (av[i])
    {
        if (!is_number(av[i]))
            return (0);
        nb_zeros += is_zero(av[i]);
        i++;
    }
    if (nb_zeros > 1)
        return (0);
    if (is_duplicate(av))
        return (0);
    return (1);
}