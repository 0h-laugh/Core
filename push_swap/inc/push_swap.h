/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:38:02 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/21 20:44:21 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void	ft_free_split(char **split_args);

//Stack init
t_stack	*init_stack(int *numbers, int size);
int		*parse_string_args(char *arg);
int		*parse_args(int argc, char **argv);

//Stack utils
void	print_stack(t_stack *stack);
int		*allocate_numbers(int argc);

//Commands
	//Swaps

	//Pushes

	//Rotates

	//Reverse rotates

//Sort

#endif
