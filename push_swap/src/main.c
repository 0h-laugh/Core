/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:25:29 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/04 17:50:56 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
