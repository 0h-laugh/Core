# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojastrze <ojastrze@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/08 16:10:02 by ojastrze          #+#    #+#              #
#    Updated: 2026/02/08 16:10:06 by ojastrze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG	= cub3d

SRCS 	=	src/main.c \
			src/casting_rays.c \
			src/check_args.c \
			src/check_map_size.c \
			src/colors_convert.c \
			src/fill_map_vals_utils.c \
			src/fill_map_vals_logic.c \
			src/load_textures.c \
			src/map_flood_check.c \
			src/map_saving.c \
			src/mapping_check.c \
			src/player_control.c \
			src/ray_utils.c
OBJS 	= ${SRCS:.c=.o}
HEADER	= -Iincludes
MLX 	= -Lminilibx-linux -lmlx_Linux -Iminilibx-linux -lXext -lX11 -lm

CC 		= gcc
CFLAGS 	= -Wall -Wextra -g

.c.o:
		@${CC} ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: ${PROG}

${PROG}: ${OBJS}
		@echo "\ncompiling libraries...\n"
		@make -s re -C ./libft
		@echo "✨ libraries compiled ✨\n"
		@${CC} ${OBJS} -Llibft -lft ${MLX} -o ${PROG}
		@echo "✨ cub3d created! ✨\n"

clean:
		@make clean -s -C ./libft
		@rm -f ${OBJS}

fclean: clean
		@make fclean -s -C ./libft
		@rm -f ${PROG} ${OBJS}
		@rm -rf libft/*.a libft/*.o libft/*.so
		@echo "\n🗑️  deleted 🗑️\n"

re: fclean all

.PHONY: all clean fclean re
