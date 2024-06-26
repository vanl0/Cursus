# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 17:42:20 by ilorenzo          #+#    #+#              #
#    Updated: 2024/01/14 17:42:24 by ilorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -g
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(MOVES) -I$(LIBFT_HEADER)
LIB_FLAGS = -lft -lftprintf -L$(LIBFT_DIR) -L$(PRINTF_DIR)


HEADERS = ./headers/push_swap.h

LIB_DIR  = ./libs/
#	LIBFT------------------------------------------
LIBFT_DIR = $(LIB_DIR)Libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(LIBFT_DIR)libft.h
#	FT_PRINTF--------------------------------------
PRINTF_DIR = $(LIB_DIR)/ft_printf/
FT_PRINTF = $(PRINTF_DIR)libftprintf.a
PRINTF_HEADER = $(PRINTF_DIR)


#	SRCS-------------------------------------------
SRCS_DIR = ./srcs/
SRCS_LS =	main.c add_data.c \
			moves_s.c moves_p.c moves_r.c moves_rr.c \
			LIS.c LIS_pb.c \
			calc_moves.c calc_moves_utils.c \
			do_moves.c do_moves_utils.c \
			check_stack.c check_arg.c \
			small_sort.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LS))
#	OBJS-------------------------------------------
OBJS_DIR = ./objs/
OBJS_LS = $(SRCS_LS:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_LS))

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(HEADERS) $(OBJS_DIR) $(OBJS) Makefile
	$(CC) $(FLAGS) $(LIB_FLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJS_DIR):
	mkdir objs
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS)
	$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(PRINTF_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(FT_PRINTF)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
