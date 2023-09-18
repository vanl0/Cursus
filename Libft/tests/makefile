CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = checker.c isalphatest.c isalnumtest.c isasciitest.c atoitest.c

all: testeo

testeo: $(OBJS) testlib.h
	gcc main.c -o mi_programa -L../ -L. -lft -ltest

%.o: %.c testlib.h
	gcc -c $(CFLAGS) $< -o $@

clean: 
	rm -f *.o
fclean: 
	rm -f *.o testeo
re: fclean all


