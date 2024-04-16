# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 23:35:56 by ojastrze          #+#    #+#              #
#    Updated: 2024/04/16 15:56:46 by ojastrze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC	= cc

FLAGS	= -Wall -Werror -Wextra

SRCDIR	= ./src/

HDRDIR	= ./inc/

SRCS	= $(SRCDIR)stack.c\
	  $(SRCDIR)main.c\
	  $(SRCDIR)fill.c\
	  $(SRCDIR)swap.c\
	  $(SRCDIR)push.c\
	  $(SRCDIR)rotate.c\
	  $(SRCDIR)reverse_rotate.c\

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(SRCDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
