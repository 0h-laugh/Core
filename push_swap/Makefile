# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 23:35:56 by ojastrze          #+#    #+#              #
#    Updated: 2024/04/15 17:17:15 by ojastrze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC	= cc

FLAGS	= -Wall -Werror -Wextra

SRCDIR	= ./src/

HDRDIR	= ./inc/

SRCS	= stack.c\
	  main.c\
	  fill.c\
	  checker.c\

OBJS	= $(SRCS:$(SRCDIR)%.c=$(SRCDIR)%.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(SRCDIR)%.o: $(SRCDIR)%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
