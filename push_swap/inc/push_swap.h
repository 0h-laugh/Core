/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:38:02 by ojastrze          #+#    #+#             */
/*   Updated: 2024/04/12 22:11:38 by ojastrze         ###   ########.fr       */
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
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
}		t_stack;

//main funtions


//stack funtions
void	fill_stack(int ac, char **av, t_stack *stack_a);

//stack utility
void	create_node(t_stack *stack, int value);

#endif
