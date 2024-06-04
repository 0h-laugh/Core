/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:38:02 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/04 18:44:53 by ojastrze         ###   ########.fr       */
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
	int				value;		//value stored in node
	int 			pos;		//position of node in stack
	struct s_stack	*next;		//pointer to next node
	struct s_stack	*prev;		//pointer to previous node
}		t_stack;

//Errors

//Stack init
t_stack	*split_init_stack(char **av);
t_stack	*init_stack(int ac, char **av);

//Node init

//Stack utils
int	check_input(char **av);

//Commands
	//Swaps
void	swap(t_stack **stack);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);

	//Pushes
void	push(t_stack **stack_a, t_stack **stack_b);

	//Rotates
void	rotate(t_stack **stack);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);

	//Reverse rotates
void	reverse_rotate(t_stack **stack);
void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

//Sort

#endif
