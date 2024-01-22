# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 13:03:26 by ilorenzo          #+#    #+#              #
#    Updated: 2024/01/18 10:50:35 by ilorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc -g -pthread
FLAGS = -Wall -Werror -Wextra

HEADER = ./philo.h
SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
 
$(NAME): $(OBJS) $(HEADER) Makefile
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

