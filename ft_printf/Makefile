# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 20:36:19 by ojastrze          #+#    #+#              #
#    Updated: 2024/03/21 19:41:00 by ojastrze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

SRCS	=	ft_printf.c\
		ft_print_char.c\
		ft_print_string.c\
		ft_print_number.c\
		ft_print_unsigned.c\
		ft_print_pointer.c\
		ft_print_hex.c\

OBJS	= $(SRCS:.c=.o)

HEADER	= ./

all:	$(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re : fclean all

.PHONY: all, clean, fclean, re
