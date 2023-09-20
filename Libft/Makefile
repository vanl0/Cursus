
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = ft_isalpha.c ft_isascii.c ft_atoi.c

#		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \

TESTSRCS := $(SRCS:.c=_test.c)
TESTOBJS := $(TESTSRCS:.c=.o) 

all: test
test: $(OBJS) libft.a main.o
	gcc $(CFLAGS) main.o libft.a -o test

libft.a: $(OBJS) $(TESTOBJS) ft_checker_test.o
	ar rcs libft.a $(OBJS) $(TESTOBJS) ft_checker_test.o

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

fclean:
	rm -f *.o libft.a libtest.a

re: fclean all
