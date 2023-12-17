
#ifndef MOVES_H
# define MOVES_H

# include "../libs/ft_printf/ft_printf.h"
# include "../libs/Libft/libft.h"
# include <stdio.h>
typedef struct s_data
{
    int val;
    int pos;
    struct s_data *next;
}t_data;


void	add_data(t_data **first, char *num);

void    index_stack(t_data **stack);

int	sorted(t_data **afirst);
void	radix_sort(t_data **afirst, t_data **bfirst, int argc);
//MOVES-----------------------------------
void	sa(t_data **afirst);
void	sb(t_data **bfirst);
void	ss(t_data **afirst, t_data **bfirst);
void	pa(t_data **afirst, t_data **bfirst);
void	pb(t_data **afirst, t_data **bfirst);
void	ra(t_data **afirst);
void	rb(t_data **bfirst);
void	rr(t_data **afirst, t_data **bfirst);
void	rra(t_data **afirst);
void	rrb(t_data **bfirst);
void	rrr(t_data **afirst, t_data **bfirst);
#endif
