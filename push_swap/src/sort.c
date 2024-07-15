/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@stundent.42warsaw.pl>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:29:19 by ojastrze          #+#    #+#             */
/*   Updated: 2024/07/09 13:15:08 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > key)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = key;
		i++;
	}
}

int get_pivot(t_stack *stack, int size)
{
	int *pivot_array;
	int i;
	t_stack *temp;

	pivot_array = (int *)malloc(sizeof(int) * size);
	if (!pivot_array)
		ft_error();
	i = 0;
	temp = stack;
	while (i < size)
	{
		pivot_array[i++] = *((int *)temp->content);
		temp = temp->next;
	}
	ft_sort_int_tab(pivot_array, size);
	i = pivot_array[size / 2];
	free(pivot_array);
	return (i);
}

void partition(t_stack **stack_a, t_stack **stack_b, int pivot, int size)
{
	int i;
	int pushed;

	i = 0;
	pushed = 0;
	while (i < size)
	{
		if (*((int *)(*stack_a)->content) < pivot)
		{
			push(stack_a, stack_b);
			pushed++;
		}
		else
			rotate(stack_a);
		i++;
	}
	while (pushed--)
		reverse_rotate(stack_b);
}

void quick_sort_util(t_stack **stack_a, t_stack **stack_b, int size)
{
	int pivot;

	if (size < 2)
		return;
	pivot = get_pivot(*stack_a, size);
	partition(stack_a, stack_b, pivot, size);

	// Recursively sort both parts
	quick_sort_util(stack_a, stack_b, size / 2);
	quick_sort_util(stack_b, stack_a, size - (size / 2)); // corrected to sort remaining elements

	while (*stack_b)
		push(stack_b, stack_a);
}

void quick_sort(t_stack **stack_a, t_stack **stack_b)
{
	int size;

	size = ft_lstsize(*stack_a);
	quick_sort_util(stack_a, stack_b, size);
}
