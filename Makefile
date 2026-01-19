# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkim2 <mkim2@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 14:18:14 by mkim2             #+#    #+#              #
#    Updated: 2026/01/14 16:42:56 by mkim2            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_printf.c \
			  ft_print_chars.c \
			  ft_print_nums.c \
			  ft_print_hex.c 

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
