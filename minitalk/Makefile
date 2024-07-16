# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 14:07:58 by ojastrze          #+#    #+#              #
#    Updated: 2024/05/11 14:08:01 by ojastrze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program rules
NAME_SERVER = server
NAME_CLIENT = client

# compiling rules
CC = cc
FLAGS = -Wall -Werror -Wextra

# directories
LIBFT = ./libft/libft.a
SRC_DIR = ./src/
HDR_DIR = ./inc/
OBJ_DIR = ./obj/

# source files
SRCS_SERVER = $(SRC_DIR)server.c
SRCS_CLIENT = $(SRC_DIR)client.c

# produce object files
OBJS_SERVER = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS_SERVER))
OBJS_CLIENT = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS_CLIENT))

all: $(NAME_SERVER) $(NAME_CLIENT)

# compile libft
$(LIBFT):
	@make -C ./libft

# program build
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	@$(CC) $(FLAGS) -I$(HDR_DIR) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	@$(CC) $(FLAGS) -I$(HDR_DIR) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

# compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -I$(HDR_DIR) -c $< -o $@

# rules
clean:
	@rm -f -r $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re