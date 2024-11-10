CC		=	cc
FLAGS		=	-Wall -Werror -Wextra
NAME		=	fdf

MLX		=	./minilibx/libmlx.a
LIBFT		=	./libft/libft.a
HDR		=	./includes/

SRC_PATH	=	./src/
OBJ_PATH	=	./obj/

SRC		=	main.c	\
			handle_file.c	\
			utils.c	\
			generate_map.c	\
			handle_color.c	\
			transformations.c	\
			hooks.c	\
			draw.c	\
			lines.c

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))
OBJ		=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

LIBS		=	-L./libft -lft -L./minilibx -lmlx -lXext -lX11 -lm
INC		=	-I$(HDR) -I./libft/inc -I./minilibx

all: $(OBJ_PATH) $(NAME)

$(LIBFT):
		@make -s -C ./libft

$(MLX):
		@make -s -C ./minilibx

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo ""
	@echo "✨ fdf created ✨"
	@echo ""
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBS) $(INC)

clean:
		@rm -f -r $(OBJ_PATH)
		@make clean -s -C ./libft
		@echo ""
		@echo "🗑️  deleted 🗑️"
		@echo ""

fclean: clean
		@rm -f $(NAME)
		@rm -f $(LIBFT)
		
re: fclean all

.PHONY: all clean fclean re
