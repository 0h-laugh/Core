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
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

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
SRCS_SERVER_BONUS = $(SRC_DIR)server_bonus.c
SRCS_CLIENT_BONUS = $(SRC_DIR)client_bonus.c

# produce object files
OBJS_SERVER = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS_SERVER))
OBJS_CLIENT = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS_CLIENT))
OBJS_SERVER_BONUS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS_SERVER_BONUS))
OBJS_CLIENT_BONUS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS_CLIENT_BONUS))

all: $(NAME_SERVER) $(NAME_CLIENT)

# compile libft
$(LIBFT):
	@make -C ./libft

# program build
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	@$(CC) $(FLAGS) -I$(HDR_DIR) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	@$(CC) $(FLAGS) -I$(HDR_DIR) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS) $(LIBFT)
	@$(CC) $(FLAGS) -I$(HDR_DIR) $(OBJS_SERVER_BONUS) $(LIBFT) -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(LIBFT)
	@$(CC) $(FLAGS) -I$(HDR_DIR) $(OBJS_CLIENT_BONUS) $(LIBFT) -o $(NAME_CLIENT_BONUS)

# compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -I$(HDR_DIR) -c $< -o $@

# rules
bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

clean:
	@rm -f -r $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	@make fclean -C ./libft

re: fclean all

.PHONY: all bonus clean fclean re
