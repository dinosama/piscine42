# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaapatou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 18:04:25 by aaapatou          #+#    #+#              #
#    Updated: 2019/06/26 18:05:07 by aaapatou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = includes

SRC = ./srcs/ft_putchar.c \
	  ./srcs/ft_swap.c \
	  ./srcs/ft_putstr.c \
	  ./srcs/ft_strlen.c \
	  ./srcs/ft_strcmp.c \

CFLAGS = -Wall -Wextra -Werror -I $(HEADER)

CC = gcc

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
