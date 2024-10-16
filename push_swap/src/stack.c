/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:41:06 by olaf              #+#    #+#             */
/*   Updated: 2024/10/05 11:53:23 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

/* Creates new stack element with provided value and returns it */

t_stack	*new_elem(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->data = value;
	new->index = 0;
	new->position = -1;
	new->target = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

/* Fills stack_a with starting values */

t_stack	*fill_with_values(int ac, char **args, char **av)
{
	t_stack		*stack_a;
	int			i;
	long int	nbr;

	stack_a = NULL;
	i = 0;
	while (i < ac)
	{
		nbr = ft_atol(args[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_error(&stack_a, NULL, args, av);
		stack_add_bottom(&stack_a, new_elem((int)nbr));
		i++;
	}
	return (stack_a);
}

/* Calculates cost of moving elements in stack_b to correct pos in stack_a */
void	calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->position) * -1;
		tmp_b->cost_a = tmp_b->target;
		if (tmp_b->target > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}

/* Finds lowest cost elem from stack_b to move to stack_a in correct pos */

void	do_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_abs_nbr(tmp->cost_a) + ft_abs_nbr(tmp->cost_b) < ft_abs_nbr
			(cheapest))
		{
			cheapest = ft_abs_nbr(tmp->cost_b) + ft_abs_nbr(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
