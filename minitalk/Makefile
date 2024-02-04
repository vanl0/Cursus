# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 12:08:05 by ilorenzo          #+#    #+#              #
#    Updated: 2023/12/01 12:32:40 by ilorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = gcc
FLAGS = -Wall -Wextra -Werror

SERV_SRCS = server.c
SERV_OBJS = $(OBJS_DIR)$(SERV_SRCS:.c=.o)
CLIENT_SRCS = client.c
CLIENT_OBJS = $(OBJS_DIR)$(CLIENT_SRCS:.c=.o)

PRINTF_DIR = ./ft_printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

OBJS_DIR = objs/
all : $(SERVER)

$(SERVER): $(SERV_OBJS) $(CLIENT) $(PRINTF) Makefile
	$(CC) $(FLAGS) $< $(PRINTF) -o $@ 

$(CLIENT): $(CLIENT_OBJS) $(PRINTF) Makefile
	$(CC) $(FLAGS) $(PRINTF) $< -o $@

$(SERV_OBJS): $(SERV_SRCS) $(OBJS_DIR)
	$(CC) -c $(FLAGS) $< -o $@
$(CLIENT_OBJS): $(CLIENT_SRCS) $(OBJS_DIR)
	$(CC) -c $(FLAGS) $< -o $@

$(PRINTF):
	make -C $(PRINTF_DIR)
	
$(OBJS_DIR):
	mkdir objs

clean:
	rm -rf $(OBJS_DIR)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -rf $(SERVER) $(CLIENT)
	make -C $(PRINTF_DIR) fclean
re: fclean all

.PHONY: all clean fclean re
