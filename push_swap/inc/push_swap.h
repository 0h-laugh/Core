/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:38:02 by ojastrze          #+#    #+#             */
/*   Updated: 2024/07/08 18:30:52 by ojastrze         ###   ########.fr       */
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
void	free_split_args(char **split_args);

//Commands
	//Swaps
void	swap(t_stack **stack);

	//Pushes
void	push(t_stack **src, t_stack **dst);

	//Rotates
void	rotate(t_stack **stack);

	//Reverse rotates
void	reverse_rotate(t_stack **stack);

//Sort
void quick_sort(t_stack **stack_a, t_stack **stack_b);
int get_pivot(t_stack *stack, int size);
void partition(t_stack **stack_a, t_stack **stack_b, int pivot, int size);
void quick_sort_util(t_stack **stack_a, t_stack **stack_b, int size);
void ft_sort_int_tab(int *tab, int size);

#endif
