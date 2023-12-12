
#ifndef MOVES_H
# define MOVES_H

# include "../libs/ft_printf/ft_printf.h"
# include "../libs/Libft/libft.h"
# include <stdio.h>
typedef struct s_data_a
{
    int val;
    int pos;
    struct s_data_a *next;
}t_data_a;

typedef struct s_data_b
{
    int val;
    int pos;
    int 
    struct s_data_b *next;
}t_data_b;

void add_data(t_data_a **first, char *num);
#endif