CC		=	cc
FLAGS		=	-Wall -Werror -Wextra
NAME		=	fdf

LIBFT		=	./libft/libft.a
SRC_PATH	=	src/
OBJ_PATH	=	obj/

SRC		=	main.c	\

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))
OBJ			=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))
INC		=	-I ./includes/

all: $(OBJ_PATH) $(NAME)

$(LIBFT):
		@make -C ./libft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
		@rm -f -r $(OBJ_PATH)
		@make clean -C ./libft

fclean: clean
		@rm -f $(NAME)
		@rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
