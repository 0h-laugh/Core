/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:55:17 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/04 17:51:04 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*split_init_stack(char **av)
{

}
//Check if ac < 2
//	(error than)
//Check if ac == 2
//	quoted string - call split_ini_stack
//Check if ac > 2
//	initalizes args into stack

t_stack	*init_stack(int ac, char **av)
{
	t_stack *stack_a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (ac < 2)
		ft_error();
	else if (ac == 2)
		a = split_init_stack(av);
	else
	{
		while (ac > i)
		{

		}
	}
}