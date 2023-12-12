#include "../headers/push_swap.h"

int check_num(char *num)
{
    
}

void add_data(t_data_a **first, char *num)
{
    t_data_a *elem;
    t_data_a *new_elem;

    new_elem = (t_data_a *)malloc(sizeof(t_data_a));
    new_elem->val = num;
    new_elem->next = NULL;
    elem = *first;
    if (!elem)
        *first = new_elem;
    else
    {
        while (elem->next)
            elem = elem->next;
        elem->next = new_elem;
    }
}