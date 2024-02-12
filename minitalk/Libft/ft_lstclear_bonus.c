#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *nextelem;
    if (lst)
    {
        while (*lst)
        {
            nextelem = (*lst)->next;
            del((*lst)->content);
            free(*lst);
            *lst = nextelem;
        }
    }
}