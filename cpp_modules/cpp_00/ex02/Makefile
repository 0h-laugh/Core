NAME = account

C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = tests.cpp Account.cpp
OBJ = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ) $(NAME)

re: fclean all