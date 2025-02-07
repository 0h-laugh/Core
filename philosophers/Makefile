CC		=	cc
FLAGS		=	-Wall -Werror -Wextra -g
NAME		=	philosophers

LIBFT		=	./libft/libft.a
HDR		=	./includes/

SRC_PATH	=	./src/
OBJ_PATH	=	./obj/

SRC		=	main.c	\

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))
OBJ		=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

LIBS		=	-L./libft -lft
INC		=	-I$(HDR) -I./libft/inc

all: $(OBJ_PATH) $(NAME)

$(LIBFT):
		@make -s -C ./libft


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJS) $(LIBFT)
	@echo ""
	@echo "✨ philosophers created ✨"
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
