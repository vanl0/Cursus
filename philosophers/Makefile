# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 15:59:22 by ilorenzo          #+#    #+#              #
#    Updated: 2024/03/26 15:59:24 by ilorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -g -pthread -Wall -Wextra


HEADER = ./header/philo.h

SRCS_DIR = srcs/
OBJS_DIR = objs/

SRCS_LS = main.c thread_utils.c table_utils.c ft_atoi.c eat_n_die.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LS))
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_LS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(HEADER) Makefile
		$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c 
		$(CC) -c $(CFLAGS) $< -o $@

$(OBJS_DIR):
	mkdir $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

do: 
	./philo 5 400 200 200
leaks:
	leaks -atE -- ./philo 5 4 4 4 5

.PHONY: all clean fclean re do
	
