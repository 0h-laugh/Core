/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:08:23 by olaf              #+#    #+#             */
/*   Updated: 2024/09/22 17:22:59 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stddef.h>
# include <../libft/inc/libft.h>

typedef struct s_stack
{
    int                 data;
    int                 index;
    int                 position;
    int                 target;
    int                 cost_a;
    int                 cost_b;
    struct s_stack *next;
}   t_stack;

/* Initialization */
t_stack *new_elem(int value);
t_stack *fill_with_values(int ac, char **av);

/* Input check */
int     ft_issorted(t_stack *stack);
int     input_check(char **av);

/* Stack utils */
t_stack *ft_stack_last(t_stack *stack);
t_stack *ft_stack_before_last(t_stack *stack);
void    stack_add_bottom(t_stack **stack, t_stack *new);
int     get_stack_size(t_stack	*stack);
void    assign_index(t_stack *stack_a, int size);
int     get_lowest_index_position(t_stack **stack);
void	get_target_position(t_stack **a, t_stack **b);

/* Sorting */
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	calculate_cost(t_stack **stack_a, t_stack **stack_b);
void	do_cheapest(t_stack **stack_a, t_stack **stack_b);
void	tiny_sort(t_stack **stack);
void	turk_sort(t_stack **stack_a, t_stack **stack_b);

/* Operations */
/* Push */
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_a, t_stack **stack_b);
/* Swap */
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);
/* Rotate */
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
/* Reverse rotate */
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);

/* Utils */
void    free_stack(t_stack **stack);
void    ft_error(t_stack **stack_a, t_stack **stack_b);
int     ft_abs_nbr(int nbr);
int     ft_issign(char c);
int	    nbstr_cmp(const char *s1, const char *s2);

#endif

