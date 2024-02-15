# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 12:08:05 by ilorenzo          #+#    #+#              #
#    Updated: 2024/02/15 13:05:06 by ilorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = gcc
FLAGS = -Wall -Wextra -Werror

SERV_SRCS = server.c
SERV_OBJS = $(SERV_SRCS:.c=.o)
CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

HEADER = minitalk.h
LIBFT_DIR = ./Libft/
LIBFT = $(LIBFT_DIR)libft.a
PRINTF_DIR = ./ft_printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

all : $(SERVER) $(CLIENT)

$(SERVER): $(SERV_OBJS) $(PRINTF) $(LIBFT) $(HEADER) Makefile
	$(CC) $(FLAGS) $< $(PRINTF) $(LIBFT) -o $@ 

$(CLIENT): $(CLIENT_OBJS) $(PRINTF) $(LIBFT) $(HEADER) Makefile
	$(CC) $(FLAGS) $(CLIENT_OBJS) $(PRINTF) $(LIBFT) -o $@

$(SERV_OBJS): $(SERV_SRCS) 
	$(CC) -c $(FLAGS) $< -o $@
$(CLIENT_OBJS): $(CLIENT_SRCS) 
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	rm -rf  $(CLIENT_OBJS) $(SERV_OBJS)
	make -C $(PRINTF_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(SERVER) $(CLIENT)
	make -C $(PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean
re: fclean all

.PHONY: all clean fclean re
