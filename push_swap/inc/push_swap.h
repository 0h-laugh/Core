/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:38:02 by ojastrze          #+#    #+#             */
/*   Updated: 2024/07/04 20:37:14 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

//creating new alias for my struct for name integrity
typedef t_list	t_stack;

//Errors
void	ft_error(void);
int		ft_isnumber(char *str);
long	ft_atol(const char *str);
int		ft_check_dup(int *numbers, int size, int number);
int		input_check(char *arg, int *numbers, int num_count);

//Stack init
t_stack		*init_stack(int ac, char **av);

//Stack utils
t_stack *init_node(int number);
t_stack	*init_one(char *arg, t_stack *stack_a, int i);
t_stack	*init_separate(char *arg, t_stack *stack_a, int i);
int		is_sorted(t_stack *stack);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

//Commands
	//Swaps

	//Pushes

	//Rotates

	//Reverse rotates

//Sort

#endif
