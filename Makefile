# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/11 22:57:31 by mkotan            #+#    #+#              #
#    Updated: 2026/03/25 17:33:30 by mkotan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
LIBFT = libft/libft.a

SRC_DIR = src
STACK_DIR = stack
OPS_DIR = operations
ALG_DIR = algorithms
METRICS_DIR = metrics
BENCH_DIR = bench

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/parse.c \
      $(SRC_DIR)/assign_index.c \
      $(SRC_DIR)/error.c \
      $(SRC_DIR)/strategy.c \
      $(SRC_DIR)/parse_helpers.c \
      $(STACK_DIR)/stack_new.c \
      $(STACK_DIR)/stack_add_back.c \
      $(STACK_DIR)/stack_size.c \
      $(STACK_DIR)/free_stack.c \
      $(OPS_DIR)/swap.c \
      $(OPS_DIR)/push.c \
      $(OPS_DIR)/rotate.c \
      $(OPS_DIR)/reverse_rotate.c \
      $(ALG_DIR)/simple_sort.c \
      $(ALG_DIR)/chunk_sort.c \
      $(ALG_DIR)/radix_sort.c \
      $(ALG_DIR)/adaptive_sort.c \
      $(METRICS_DIR)/disorder.c \
      $(BENCH_DIR)/benchmark.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@make -C libft

clean:
	rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re libft
