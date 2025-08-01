CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone

SRC_PATH = ./
OBJ_PATH = ./

SRC = megaphone.cpp
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo ""
	@echo " ✨  PhoneBook created  ✨"
	@echo ""
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@echo ""
	@echo "🗑️ Deleted object files 🗑️"
	@echo ""

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@echo ""
	@echo "🗑️ PhoneBook deleted 🗑️"
	@echo ""

re: clean fclean all

.PHONY: all clean fclean re