/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:25:29 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/12 22:17:10 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int ac, char **av)
{
	//Declare and initalize stack
	t_stack stack_a;
	t_stack stack_b;

	stack_a.top = NULL;
	stack_b.top = NULL;
	//take input and put it into stack
	fill_stack(ac, av, &stack_a);
	//Sort
	
	//Output of instructions/stack
	return (0);
}