# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 12:20:22 by alejandj          #+#    #+#              #
#    Updated: 2025/04/10 16:13:03 by alejandj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

# Libft
LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

SRC =	src/push_swap.c		\
		src/ps_utils.c		\
		src/sort_simple.c	\
		src/rules/swap.c	\
		src/rules/push.c	\
		src/rules/rotate.c	\
		src/rules/reverse_rotate.c	\

OBJECTS = ${SRC:.c=.o}

all: $(NAME)

# Compilar el ejecutable
$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) -L$(LIBDIR) -lft -o $(NAME)

# Compilar la biblioteca
$(LIBFT):
	make -C $(LIBDIR)

%.o: %.c push_swap.h $(LIBDIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECTS) $(OBJECTS_BONUS)
	@echo "Object files removed."

fclean: clean
	@rm -rf $(NAME)
	@echo "Executable $(NAME) removed"

re: fclean all

.PHONY: all clean fclean re