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

#program name
NAME	= push_swap

#compiling utils
CC	= cc
FLAGS	= -Wall -Werror -Wextra -I

#directories
LIBFT	= ./libft/libft.a
SRC_DIR	= ./src/
HDR_DIR	= ./inc/
OBJ_DIR	= ./obj/

#source files
SRCS	= $(SRC_DIR)main.c\
	  $(SRC_DIR)stack_utils.c\
	  $(SRC_DIR)input_check.c\
	  $(SRC_DIR)op.c\
	  $(SRC_DIR)stack.c\
	  $(SRC_DIR)sort.c\

#produce object files
OBJS	= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all:	$(NAME)

#compile libft
$(LIBFT):
		@make -C ./libft

#program build
$(NAME): $(OBJS) $(LIBFT)
		@$(CC) $(FLAGS) $(HDR_DIR) $(OBJS) $(LIBFT) -o $(NAME)

#compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		@mkdir -p $(@D)
		@$(CC) $(FLAGS) $(HDR_DIR) -c $< -o $@

#rules
clean:
		@rm -f -r $(OBJ_DIR)
		@make clean -C ./libft

fclean: clean
		@rm -f $(NAME)
		@rm -f $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re
