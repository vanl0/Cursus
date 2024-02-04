
NAME = fdf

CC = gcc -g
FLAGS = -Wall -Werror -Wextra
LIB_FLAGS = -lmlx -lm -lft -lftprintf -L$(LIBFT_DIR) -L$(LIBMLX_DIR) -L$(PRINTF_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(LIBFT_HEADER) -I$(LIBMLX_HEADER) -I$(HEADERS_DIR)


LIB_DIR = ./libs
#	HEADERS----------------------------------------
HEADERS_DIR = ./headers/
HEADERS_LS = fdf.h struct.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LS))
#	LIBFT------------------------------------------
LIBFT_DIR = $(LIB_DIR)/Libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(LIBFT_DIR)
#	LIBMLX-----------------------------------------
LIBMLX_DIR = $(LIB_DIR)/minilibx_macos/
LIBMLX = $(LIBMLX_DIR)libmlx.a
LIBMLX_HEADER = $(LIBMLX_DIR)
#	FT_PRINTF--------------------------------------
PRINTF_DIR = $(LIB_DIR)/ft_printf/
FT_PRINTF = $(PRINTF_DIR)libftprintf.a
PRINTF_HEADER = $(PRINTF_DIR)
#	SRCS-------------------------------------------
SRCS_DIR =./sources/
SRCS_LS = main.c draw.c input.c read_map.c control.c read_map_utils.c \
			iso_transform.c connect_points.c input_utils.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LS))
#	OBJS-------------------------------------------
OBJS_DIR = ./objects/
OBJS_LS = $(SRCS_LS:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_LS))

all : $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(FT_PRINTF) $(HEADERS) $(OBJS_DIR) $(OBJS) Makefile
	$(CC) $(FLAGS) $(LIB_FLAGS) $(INCLUDES) $(OBJS) -o $(NAME)


$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS)
	$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX): 
	make -C $(LIBMLX_DIR)

$(FT_PRINTF):
	make -C $(PRINTF_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(LIBMLX_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(LIBMLX)
	rm -f $(FT_PRINTF)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


