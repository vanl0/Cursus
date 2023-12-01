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

SRCS = $(SERV_SRCS) $(CLIENT_SRCS)
OBJS_DIR = objs/
all : $(SERVER)

$(SERVER): $(SERV_OBJS) $(CLIENT)
	$(CC) $(FLAGS) $< -o $@

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(FLAGS) $< -o $@

$(SERV_OBJS): $(SERV_SRCS) $(OBJS_DIR)
	$(CC) -c $(FLAGS) $< -o $@
$(CLIENT_OBJS): $(CLIENT_SRCS) $(OBJS_DIR)
	$(CC) -c $(FLAGS) $< -o $@

$(OBJS_DIR):
	mkdir objs
clean:
	rm -rf $(OBJS_DIR)
fclean: clean
	rm -rf $(SERVER) $(CLIENT)
re: fclean all

.PHONY: all clean fclean re
