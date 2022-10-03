# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaapatou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 20:25:17 by aaapatou          #+#    #+#              #
#    Updated: 2019/06/27 18:29:01 by aaapatou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRC = ft_atoi.c ft_putchar.c ft_putnbr.c ft_putstr.c main.c op.c

CFLAGS = -Wall -Wextra -Werror

CC = gcc

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
