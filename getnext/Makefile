SRCS = get_next_line.c get_next_line_utils.c 
BUFF = 15

all: $(SRCS) get_next_line.h
	gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFF) $(SRCS) main.c
	./a.out
