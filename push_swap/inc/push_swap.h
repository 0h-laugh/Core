/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:38:02 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/19 12:09:31 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

//My double linked list structure
typedef struct s_stack
{
	int				data;		//value stored in node
	int 			pos;		//position of node in stack
	int 			cost;		//result of counting cost function
	int 			median;		//median of all values
	int				cheapest;	//here i store what has the lowest cost
	struct s_stack	*target;	//pointer to target node
	struct s_stack	*next;		//pointer to next node
	struct s_stack	*prev;		//pointer to previous node
}		t_stack;

//Errors

//Stack init

//Node init

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

//Sort

#endif
