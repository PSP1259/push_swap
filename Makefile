# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-jos <juan-jos@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/01 16:28:57 by juan-jos          #+#    #+#              #
#    Updated: 2026/11/19 14:12:56 by juan-jos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

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
		parse_flags.c \
		push_swap_utils.c \
		algorithm_simple.c \
		algorithm_medium.c \
		algorithm_complex.c \
		compute_disorder.c \
		rank.c \
		bench.c \
		sort_small.c

OBJS = $(SRCS:.c=.o)

SHARED_SRCS =	list_make.c \
				stack_moves.c \
				push_swap_utils.c \
				ops_swap_push.c \
				ops_rotate.c \
				ops_rev_rotate.c \
				record.c \
				parse.c

BONUS_SRCS =	checker_bonus.c \
				checker_read_bonus.c

SHARED_OBJS = $(SHARED_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(SHARED_OBJS) $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SHARED_OBJS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(BONUS_OBJS): checker_bonus.h

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re