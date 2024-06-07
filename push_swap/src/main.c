/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:25:29 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/04 18:44:38 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void print_stack(t_stack *stack)
{
 t_stack *current = stack;
 while (current != NULL)
 {
  printf("%d\n", current->value);
  current = current->next;
 }
}

int main(int ac, char **av)
{
	t_stack *stack_a;

	stack_a = init_stack(ac, av);
	if (!a)
	{
		ft_free(&a);
		ft_error();
	}
	if (!check_input(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!is_sorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
