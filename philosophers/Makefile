NAME = philo
CC = gcc
CFLAGS = -g -pthread -Wall -Wextra

SRCS_DIR = srcs/
OBJS_DIR = objs/

SRCS_LS = main.c init.c thread_utils.c list_utils.c clock.c ft_atoi.c eat_n_die.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LS))
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_LS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c 
		$(CC) -c $(CFLAGS) $< -o $@

$(OBJS_DIR):
	mkdir $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

leaks: $(NAME)
	valgrind --leak-check=full ./$(NAME) 5 400 200 200
do: 
	./philo 5 400 200 200

re: fclean all

.PHONY: all clean fclean re leaks do
	
