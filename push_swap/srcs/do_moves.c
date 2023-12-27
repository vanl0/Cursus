#include "../headers/push_swap.h"


t_data  *get_cheapest(t_data **b_stack)
{
    t_data  *elem;
    t_data  *min_elem;

    elem = *b_stack;
    min_elem = elem;
    while (elem)
    {
        if (min_elem->moves > elem->moves)
            min_elem = elem;
        elem = elem->next;
    }
    return (min_elem);
}

void    read_moves(t_data *b_elem, t_data **a_stack, t_data **b_stack)
{
    while (b_elem->ra)
    {
        ra(a_stack);
        b_elem->ra--;
        printf("ra\n");
    }
    while (b_elem->rb)
    {
        rb(b_stack);
        b_elem->rb--;
        printf("rb\n");
    }
    while (b_elem->rr)
    {
        rr(a_stack, b_stack);
        b_elem->rr--;
        printf("rr\n");
    }
    while (b_elem->rra)
    {
        rra(a_stack);
        b_elem->rra--;
        printf("rra\n");
    }
    while (b_elem->rrb)
    {
        rrb(b_stack);
        b_elem->rrb--;
        printf("rrb\n");
    }
    while (b_elem->rrr)
    {
        rrr(a_stack, b_stack);
        b_elem->rrr--;
        printf("rrr\n");
    }
    pa(a_stack, b_stack);
    printf("pa\n");
}
void    do_moves(t_data **a_stack, t_data **b_stack)
{
    t_data  *min_elem;
    t_data  *elem;
    elem = *a_stack;
    min_elem = get_cheapest(b_stack);

    printf("min: %d\n", min_elem->val);
    read_moves(min_elem, a_stack, b_stack);
}