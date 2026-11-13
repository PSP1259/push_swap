# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-jos <juan-jos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/01 16:28:57 by juan-jos          #+#    #+#              #
#    Updated: 2026/11/13 11:31:01 by juan-jos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Werror -Wall -Wextra

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	list_make.c \
		main.c \
		stack_moves.c \
		ops_swap_push.c \
		ops_rotate.c \
		ops_rev_rotate.c \
		record.c \
		parse.c \
		push_swap_utils.c \
		algorithm_simple.c \
		algorithm_medium.c \
		algorithm_complex.c \
		compute_disorder.c \
		rank.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re