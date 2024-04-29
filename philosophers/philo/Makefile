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
CFLAGS = -g  -pthread -Wall -Wextra -Werror


HEADER = ./header/philo.h

SRCS_DIR = srcs/
OBJS_DIR = objs/

SRCS_LS = main.c threads.c thread_utils.c table_utils.c ft_atoi.c eat_n_die.c get_set.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LS))
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_LS:.c=.o))

GRAY = \033[2;29m
GREEN = \033[0;32m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(GRAY)$(shell printf '%*s' $(shell tput cols) | tr ' ' '-')$(NC)"
	@echo "$(GRAY)$(CC) $(CFLAGS) $(OBJS) -o $@ $(NC)"
	@echo "$(GREEN)$(NAME) compiled succesfully$(NC)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER) Makefile
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo "$(GRAY)$(CC) -c $(CFLAGS) $< -o $@ $(NC)"

$(OBJS_DIR):
	@mkdir $@

clean:
	@echo "$(GREEN)All objects  removed $(NC)"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "$(GREEN)All binaries removed $(NC)"
	@rm -f $(NAME)

re: fclean all

do: 
	./philo 4 450 200 200 10
leaks:
	leaks --atExit -- ./philo 5 450 200 200 10
valg:
	valgrind --leak-check=full ./philo 5 450 200 200 8

.PHONY: all clean fclean re