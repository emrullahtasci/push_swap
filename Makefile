# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/11 22:57:31 by mkotan            #+#    #+#              #
#    Updated: 2026/03/25 15:46:22 by etasci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.

LIBFT		= libft/libft.a

SRC			= src/main.c \
			  src/parse.c \
			  src/error.c \
			  src/assign_index.c \
			  stack/stack_new.c \
			  stack/stack_add_back.c \
			  stack/stack_size.c \
			  stack/free_stack.c \
			  operations/swap.c \
			  operations/push.c \
			  operations/rotate.c \
			  operations/reverse_rotate.c \
			  algorithms/simple_sort.c \
			  algorithms/chunk_sort.c \
			  algorithms/radix_sort.c \
			  algorithms/adaptive_sort.c \
			  metrics/disorder.c \
			  bench/benchmark.c

OBJ			= $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
