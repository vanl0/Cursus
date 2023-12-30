
#include "../headers/push_swap.h"

int    get_min(t_data **a_stack, t_data *b_elem)
{
    t_data  *elem;
    int     min;
    int     target_pos;
    int     pos;

    elem = *a_stack;
    min = elem->val;
    target_pos = 0;
    pos = 0;
    while (elem)
    {
        if (elem->val < min)
        {
            min = elem->val;
            target_pos = pos;
        }
        pos++;
        elem = elem->next;
    }
    b_elem->target = min;
    if (target_pos <= pos / 2)
	{
		b_elem->ra = target_pos;
		return (target_pos);
	}
	else
	{
		b_elem->rra = pos - target_pos;
		return (pos - target_pos);
	}
}
