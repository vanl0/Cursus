NAME = philo
CC = gcc
CFLAGS = -g -pthread -Wall -Werror -Wextra

SRCS_DIR = srcs/
OBJS_DIR = objs/

SRCS_LS = main.c \
	            ft_atoi.c \
		              table_utils.c \
			                thread_utils.c \
					          clock.c

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LS))
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_LS:.c=.o))
	DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) | $(OBJS_DIR)
	    $(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	    $(CC) $(CFLAGS) -MMD -MP -MF $(@:.o=.d) -c $< -o $@

$(OBJS_DIR):
	    mkdir -p $@

clean:
	    @echo "Limpiando archivos objeto..."
	        rm -rf $(OBJS_DIR)

fclean: clean
	    @echo "Limpiando ejecutables..."
	        rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
	
