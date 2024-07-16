/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@stundent.42warsaw.pl>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:40:44 by ojastrze          #+#    #+#             */
/*   Updated: 2024/07/16 12:59:27 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_catch(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	int pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error: Bad usage!\n");
		ft_printf("Type: ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID:%d\n", pid);
	ft_printf("Waiting for a message...\n");
	while (ac == 1)
	{
		signal(SIGUSR1, ft_catch);
		signal(SIGUSR2,	ft_catch);
		pause ();
	}
	return (0);
}