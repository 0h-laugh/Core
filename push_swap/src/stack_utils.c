/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:16:42 by ojastrze          #+#    #+#             */
/*   Updated: 2024/06/05 08:24:01 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function returns the last element of stack
t_stack *ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// This functions returns size of stack
t_stack	*ft_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}