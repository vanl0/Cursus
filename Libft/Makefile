# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/17 16:54:59 by ilorenzo          #+#    #+#              #
#    Updated: 2023/09/18 17:13:21 by ilorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c

TESTPATH  = tests
TESTSRCS := $(wildcard $(TESTPATH)/*.c) 
TESTOBJS := $(patsubst $(TESTPATH)/%.c,$(TESTPATH)/%.o,$(TESTSRCS))

all: test

test: $(OBJS) libft.a libtest.a
	gcc $(CFLAGS) main.c libft.a libtest.a -o test 
#----------------------------------------------------------------------
libft.a: $(OBJS)
	ar rcs libft.a $(OBJS)
$(OBJS): $(SRCS)
	gcc -c $(CFLAGS) $< -o $@
#-----------------------------------------------------------------------
libtest.a: $(TESTOBJS)
	ar rcs libtest.a $(TESTOBJS)
	rm -f tests/*.o

$(TESTOBJS): $(TESTSRCS)
	gcc -c $(CFLAGS)  $< -o $@

#------------------------------------------------------------------------
clean: 
	rm -f *.o
fclean: 
	rm -f *.o testeo libtest.a libft.a
re: fclean all
