/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:38:02 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/17 15:39:19 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_node
{
	int				data;
	int 			pos;
	struct s_node	*next;
	struct s_node	*prev;
}		t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bot;
}		t_stack;

//main funtions


//check input
int	check_input(char **av);

//stack funtions
void	fill_stack(int ac, char **av, t_stack *stack_a);

//stack utility
void	create_node(t_stack *stack, int value);

//stack operations
//swaps
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_ab(t_stack *stack_a, t_stack *stack_b);

//pushes
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);

//rotates
void	rotate_a(t_stack *stack_a);
void	rotate_b(t_stack *stack_b);
void	rotate_ab(t_stack *stack_a, t_stack *stack_b);

//reverse rotates
void	reverse_rotate_a(t_stack *stack_a);
void	reverse_rotate_b(t_stack *stack_b);
void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);

#endif
