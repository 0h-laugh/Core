# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 23:35:56 by ojastrze          #+#    #+#              #
#    Updated: 2024/04/23 17:02:24 by ojastrze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC	= cc
FLAGS	= -Wall -Werror -Wextra -I

LIBFT	= ./libft/libft.a
SRC_DIR	= ./src/
HDR_DIR	= ./inc/
OBJ_DIR	= ./obj/

SRCS	= $(SRC_DIR)main.c\
	  $(SRC_DIR)swap.c\
	  $(SRC_DIR)push.c\
	  $(SRC_DIR)rotate.c\
	  $(SRC_DIR)reverse_rotate.c\

OBJS	= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))


all:	$(LIBFT) $(NAME)

$(LIBFT):
		@make -C ./libft

$(NAME): $(OBJS) $(LIBFT)
		@$(CC) $(FLAGS) $(HDR_DIR) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		@mkdir -p $(@D)
		@$(CC) $(FLAGS) $(HDR_DIR) -c $< -o $@

clean:
		@rm -f -r $(OBJ_DIR)
		@make clean -C ./libft

fclean: clean
		@rm -f $(NAME)
		@rm -f $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re
