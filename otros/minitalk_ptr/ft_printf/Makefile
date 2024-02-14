# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 18:46:46 by ilorenzo          #+#    #+#              #
#    Updated: 2023/10/04 15:30:27 by ilorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libftprintf.a
SRCS:= ft_printf.c ft_putchar.c put_var.c ft_putstr.c ft_putnbr.c ft_puthex.c\
		ft_putpoint.c ft_putunsig.c
OBJS:= $(SRCS:.c=.o)
CC:= gcc
FLAGS:= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h Makefile
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
