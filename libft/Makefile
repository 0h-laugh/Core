# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojastrze <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 15:05:33 by ojastrze          #+#    #+#              #
#    Updated: 2024/03/09 12:22:53 by ojastrze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FULL_SQUARE = █

EMPTY_SQUARE = ░

NAME	= libft.a

SRCS	=	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

OBJS	= $(SRCS:.c=.o)

HEADER = ./

CC	= cc

FLAGS	= -Wall -Wextra -Werror

.c.o:
	@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Compiling libft:"
	@sleep 0.1 && clear && echo "$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(EMPTY_SQUARE)"
	@sleep 0.1 && clear && echo "$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)$(FULL_SQUARE)"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@clear
	@echo "Success!"

all: $(NAME)

clean:
	rm -f $(OBJS)
	@clear
	@echo "Objects threw away!"

fclean: clean
	rm -f $(NAME)
	@clear
	@echo "Library clean!"

re: fclean all
	@echo "Library redone!"

.PHONY: all, clean, fclean, re
