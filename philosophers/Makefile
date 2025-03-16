CC		=	cc
FLAGS		=	-Wall -Werror -Wextra
NAME		=	philo

HDR		=	./includes/

SRC_PATH	=	./src/
OBJ_PATH	=	./obj/

SRC		=	main.c \
			forks.c \
			utils.c \
			check.c \
			parser.c \

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))
OBJ		=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

INC		=	-I$(HDR) -I./libft/inc

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	@echo ""
	@echo "✨ philosophers created ✨"
	@echo ""
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INC)

clean:
		@rm -f -r $(OBJ_PATH)
		@echo ""
		@echo "🗑️  deleted 🗑️"
		@echo ""

fclean: clean
		@rm -f $(NAME)
		
re: fclean all

.PHONY: all clean fclean re
