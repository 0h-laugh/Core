/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:38:02 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/17 16:18:22 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>

//My double linked list structure
typedef struct s_node
{
	int				data;		//value stored in node
	int 			pos;		//position of node in stack
	int 			cost;		//result of counting cost function
	int 			median;		//median of all values
	int				cheapest;	//here i store what has the lowest cost
	struct s_node	*target;	//pointer to target node
	struct s_node	*next;		//pointer to next node
	struct s_node	*prev;		//pointer to previous node
}		t_node;

//Errors

//Check input
int	check_input(char **av);

//Stack init
void	fill_stack(int ac, char **av, t_stack *stack_a);

//Node init
void	create_node(t_stack *stack, int value);

//Stack utils

//Commands
	//Swaps
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_ab(t_stack *stack_a, t_stack *stack_b);

	//Pushes
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);

	//Rotates
void	rotate_a(t_stack *stack_a);
void	rotate_b(t_stack *stack_b);
void	rotate_ab(t_stack *stack_a, t_stack *stack_b);

	//Reverse rotates
void	reverse_rotate_a(t_stack *stack_a);
void	reverse_rotate_b(t_stack *stack_b);
void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);

//Algorithms

#endif
