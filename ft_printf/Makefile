# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 20:36:19 by ojastrze          #+#    #+#              #
#    Updated: 2024/03/11 15:57:49 by ojastrze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FULL_SQUARE = █

EMPTY_SQUARE = ░

NAME	= libftprintf.a

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

SRCS	=

OBJS	= $(SRCS:.c-.o)

HEADER	= ./

.c.o:
	@$(CC)$(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Compiling libftprintf:"
	@sleep 0.1 && clear && echo "$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@clear
	@echo "Success!"

all: $(NAME)

clean:
	rm -f $(OBJS)
	@clear
	@echo "Objects threw away!"

fclean: clean
	rm -f $(NAME)
	@clear
	@echo "Library clean!"

re : fclean all
	@echo "Library redone!"

.PHONY: all, clean, fclean, re
