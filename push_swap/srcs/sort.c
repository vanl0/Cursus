#include "../headers/push_swap.h"

void    move_to_b(t_data **afirst, t_data **bfirst, int i, int argc)
{
        int     bit;
        int     count = 0;

        bit = 0;

        while (count < argc - 1)
        {
                bit = ((*afirst)->pos >> i) & 1;
                if (bit == 0)
                        pb(afirst, bfirst);
                else
                        ra(afirst);
                count++;
        }
}

void	radix_sort(t_data **afirst, t_data **bfirst, int argc)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		move_to_b(afirst, bfirst, i, argc);
		while (*bfirst)
		{
			pa(afirst, bfirst);
		}
		i++;
	}
}
