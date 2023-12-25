#include "../headers/push_swap.h"

int get_stack_len(t_data **stack)
{
    int len;
    t_data  *elem;

    if (!stack || !(*stack))
        return (0);
    len = 0;
    elem = *stack;
    while (elem)
    {
        len++;
        elem = elem->next;
    }
    return (len);
}

int calc_moves_b(int i, int b_len, t_data *b_elem)
{
    if (i <= b_len / 2)
    {
        b_elem->rb = i;
        return (i + 1);
    }
    else
    {
        b_elem->rrb = b_len - i;
        return (b_len - i + 1);
    }
}

int calc_moves_a(t_data **a_stack, t_data *b_elem)
{
    int target_pos;
    t_data  *elem;
    int pos;

    elem = *a_stack;
    pos = 0;
    target_pos = 0;
    while (elem)
    {
        if (elem->val > b_elem->val)
        {
            if (!b_elem->target)
            {
                b_elem->target = elem->val;
                target_pos = pos;
            }else if (elem->val < b_elem->target)
            {
                b_elem->target = elem->val;
                target_pos = pos;
            }
        }
        elem = elem->next;
        pos++;
    }
    if (!b_elem->target)
    {
        b_elem->target = (*a_stack)->val;
        return (0);
    }
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

void    set_moves(t_data **a_stack, t_data **b_stack)
{
    int b_len;
    int a_len;
    int i;
    t_data  *b_elem;

    a_len = get_stack_len(a_stack);
    b_len = get_stack_len(b_stack);

    b_elem = *b_stack;
    i = 0;
    while (b_elem)
    {
        b_elem->moves = calc_moves_b(i, b_len, b_elem) + calc_moves_a(a_stack, b_elem);
        b_elem = b_elem->next;
        i++;
    }
}