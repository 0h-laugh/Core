/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@stundent.42warsaw.pl>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:40:44 by ojastrze          #+#    #+#             */
/*   Updated: 2024/07/17 18:16:35 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

//Included files
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

//Included libraries
# include <signal.h>

//Client
void	ft_send(int pid, char i);

//Server
void	ft_catch(int signal);

#endif